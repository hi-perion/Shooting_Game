#include "player.h"
#include "game.h"

// コンストラクタ
Player::Player() {
    graphicHandle = LoadGraph("player.png");   // グラフィックハンドルの取得
    GetGraphSize(graphicHandle, &width, &height);   // 画像の横幅、高さの取得
    existFlag = ON;   // 存在フラグの設定
    timer = 0;   // タイマーの初期値の設定
    hitFlag = OFF;   // 衝突フラグの設定
    X = PLAYER_SET_POSITION_X;   // x座標の初期値の設定
    Y = PLAYER_SET_POSITION_Y;   // y座標の初期値の設定
    bulletCreate();   // 弾丸作成
    shotButtonFlag = OFF;   // ショットボタンフラグの初期値を設定
    life = MAX_PLAYER_LIFE;   // 残機の初期値を設定
    LoadDivGraph("explosion.png", 8, 1, 8, 80, 80, explosions, TRUE); // 分割画像(爆発エフェクト)を配列に格納
    explosionSoundHandle =  LoadSoundMem("player_explosion.mp3");   // 爆発音の取得
    ChangeVolumeSoundMem(255*75/100, explosionSoundHandle);   // 爆発音の音量を調節
    shotSoundHandle =  LoadSoundMem("player_shot.wav");   // ショット音の取得
    ChangeVolumeSoundMem(255*25/100, shotSoundHandle);   // ショット音の音量を調節
}

// デストラクタ
Player::~Player() {
    // バレットオブジェクトをすべて破棄
    for(int i=0; i<MAX_PLAYER_BULLET; i++) {
        delete bullets[i];
    }
}

// 描画処理関数
void Player::draw() {
    if(existFlag==ON && hitFlag==OFF) {
        DrawGraph(X, Y, graphicHandle, TRUE);
    }
}

// 移動処理関数
void Player::move() {
    
    // 移動係数の設定
    if(CheckHitKey(KEY_INPUT_LEFT)==ON && CheckHitKey(KEY_INPUT_UP)==ON) {
        moveCoefficient = 0.71f;  // float型の数値は末尾にfを付けること
    }
    if(CheckHitKey(KEY_INPUT_RIGHT)==ON && CheckHitKey(KEY_INPUT_UP)==ON) {
        moveCoefficient = 0.71f;
    }
    if(CheckHitKey(KEY_INPUT_LEFT)==ON && CheckHitKey(KEY_INPUT_DOWN)==ON) {
        moveCoefficient = 0.71f;
    }
    if(CheckHitKey(KEY_INPUT_RIGHT)==ON && CheckHitKey(KEY_INPUT_DOWN)==ON) {
        moveCoefficient = 0.71f;
    }
    if(CheckHitKey(KEY_INPUT_RIGHT)==ON || CheckHitKey(KEY_INPUT_LEFT)==ON || 
        CheckHitKey(KEY_INPUT_UP)==ON || CheckHitKey(KEY_INPUT_DOWN)==ON) {
        moveCoefficient = 1.0f;
    }
    
    // 上下左右移動の処理
    if(CheckHitKey(KEY_INPUT_RIGHT)==ON && X+width<WINDOW_WIDTH) {
        X += PLAYER_SPEED*moveCoefficient;   // 自動的にint型に型変換される模様
    }
    if(CheckHitKey(KEY_INPUT_LEFT)==ON && X>0) {
        X -= PLAYER_SPEED*moveCoefficient;
    }
    if(CheckHitKey(KEY_INPUT_UP)==ON && Y>0) {
        Y -= PLAYER_SPEED*moveCoefficient;
    }
    if(CheckHitKey(KEY_INPUT_DOWN)==ON && Y+height<WINDOW_HEIGHT) {
        Y += PLAYER_SPEED*moveCoefficient;
    }
}


// 弾丸作成関数
void Player::bulletCreate() {
    // 弾丸を作成して配列に格納
    for(int i=0; i<MAX_PLAYER_BULLET; i++) {
        bullets[i] = new Bullet("player_bullet.png");   // 弾丸作成
    }
}


// 弾丸射出処理関数
void Player::shot() {
    
    // Zボタンが押された場合の弾丸の初期位置と存在フラグの設定
    if(CheckHitKey(KEY_INPUT_Z)==ON) {
        if(shotButtonFlag==OFF) {
            for(int i=0; i<MAX_PLAYER_BULLET; i++) {
                if(bullets[i]->getExistFlag()==OFF) {
                    bullets[i]->setX(X+11);
                    bullets[i]->setY(Y);
                    bullets[i]->setExistFlag(ON);  // 弾丸の存在フラグをONにする
                    break;
                }
            }
        }

        // ショット音を再生
        PlaySoundMem(shotSoundHandle, DX_PLAYTYPE_BACK, TRUE);
        
        shotButtonFlag = ON;   // 自動連射防止措置
    } else {
        shotButtonFlag = OFF;   // 自動連射防止措置
    }

    // 弾丸の描画と移動処理
    for(int i=0; i<MAX_PLAYER_BULLET; i++) {
        if(bullets[i]->getExistFlag()==ON) {
            bullets[i]->draw();
            bullets[i]->playerBulletMove();
        }
        // 弾丸が画面の外に出たら存在フラグをOFFに戻す
        if(bullets[i]->getX()<0 || bullets[i]->getX()>WINDOW_WIDTH ||
            bullets[i]->getY()<0 || bullets[i]->getY()>WINDOW_HEIGHT) {
            bullets[i]->setExistFlag(OFF);
        }
    }
}


// 残機を減らす処理をする関数
void Player::die() {
    /* 敵弾に当たったら存在フラグがOFFになっているので、
       残機を減らしてフラグをONに戻す */
    if(existFlag==OFF) {
        life -= 1;
        existFlag = ON;
    }
}

// 爆発処理関数
void Player::explode() {
    // 敵弾または敵本体に衝突した場合
    if(hitFlag==ON) {

        // タイマーを進める
        timer++;
        
        // 敵弾または敵本体と衝突時の座標を取得
        if(timer==1) {
            collisionX = X;
            collisionY = Y;
        }

        // 爆発エフェクトを描画
        indexNumber = timer/4 % 8;
        DrawGraph(collisionX-17, collisionY-19, explosions[indexNumber], TRUE);

        // 爆発音を再生
        if(CheckSoundMem(explosionSoundHandle)==0) {
            PlaySoundMem(explosionSoundHandle, DX_PLAYTYPE_BACK, TRUE);
        }
        
    }
}

// 待機処理関数
void Player::wait() {
    if(life>=0) {
        if(timer==30) {   // 爆発時から0.5秒経過後
            hitFlag = OFF;   // 衝突フラグをOFFに戻す
            timer = 0;   // タイマーをリセット
            X = PLAYER_SET_POSITION_X;   // 復活後のプレイヤーのx座標の位置
            Y = PLAYER_SET_POSITION_Y;   // 復活後のプレイヤーのy座標の位置
        }
    }
    
}

// ゲームオーバー(残機0)時の処理関数
void Player::gameOver() {
    if(life<0) {
        if(timer==30) {   // 爆発時から0.5秒経過後
            Game::setGameState(GAME_OVER);   // ゲームオーバー画面へ移行
        }
    }
}


// 敵またはボスとの衝突処理関数
void Player::crash(int targetX, int targetY,
                    int targetWidth, int targetHeight,
                    int* pTargetExistFlag, int* pTargetHitFlag) {
    
    // 敵またはボスと衝突した場合
    if(((X > targetX && X < targetX+targetWidth) || (targetX > X && targetX < X+width)) &&
       ((Y > targetY && Y < targetY+targetHeight) || (targetY > Y && targetY < Y+height))) {
        existFlag = OFF;   // 自身(プレイヤー)の存在フラグをOFFにする
        hitFlag = ON;   // 自身(プレイヤー)の衝突フラグをONにする
        *pTargetExistFlag = OFF;   // 衝突した対象の存在フラグをOFFにする
        *pTargetHitFlag = ON;   // 衝突した対象の衝突フラグをONにする
    }
    
}
