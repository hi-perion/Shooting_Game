#include "boss.h"
#include "game.h"

// コンストラクタ
Boss::Boss() {
    existFlag = ON;   // 存在フラグの設定
    hitFlag = OFF;   // 衝突フラグの設定
    vectorX = LEFT_DIRECTION;
    counter = 0;   // ボスが保有する時間の初期値の設定
    timer = 0;   // タイマーの初期値の設定
    graphicHandle = LoadGraph("boss.png");   // グラフィックハンドルの取得
    GetGraphSize(graphicHandle, &width, &height);   // 画像の横幅、高さの取得
    X = BOSS_SET_POSITION_X;   // x座標の初期値の設定
    Y = BOSS_SET_POSITION_Y;   // y座標の初期値の設定
    bulletCreate();   // 弾丸作成
    life = MAX_BOSS_LIFE;   // 残機の初期値を設定
    LoadDivGraph("explosion.png", 8, 1, 8, 80, 80, explosions, TRUE); // 分割画像(爆発エフェクト)を配列に格納
    explosionSoundHandle = LoadSoundMem("boss_explosion.wav");   // 爆発音の取得
    ChangeVolumeSoundMem(255*60/100, explosionSoundHandle);   // 爆発音の音量を調節
}

// デストラクタ
Boss::~Boss() {
    // バレットオブジェクトをすべて破棄
    for(int i=0; i<MAX_BOSS_BULLET; i++) {
        delete bullets[i];
    }
}

// x座標の向きのセッター
void Boss::setVectorX(int direction) {
    vectorX = direction;
}

// 描画処理関数
void Boss::draw() {
    if(existFlag==ON && timer==0) {
        
        // ボスを描画
        DrawGraph(X, Y, graphicHandle, TRUE);

        // ボスが保有する時間を進める
        if(counter<360) {
            counter++;
        }
        if(counter==360) {
            counter = 0;
        }
        
    }
}


// 移動処理関数
void Boss::move() {
    X = X + BOSS_SPEED*vectorX;
    if(X <= 0) {
        vectorX = RIGHT_DIRECTION;
    }
    if(X+width > WINDOW_WIDTH) {
        vectorX = LEFT_DIRECTION;
    }
}

// 弾丸作成関数
void Boss::bulletCreate() {
    // 弾丸を作成して配列に格納
    for(int i=0; i<MAX_BOSS_BULLET; i++) {
        bullets[i] = new Bullet("boss_bullet.png");   // 弾丸作成
    }
}


// 弾丸射出処理関数
void Boss::shot() {

    if(existFlag==ON && hitFlag==OFF && timer==0) {

        // 0.1秒ごとに弾丸を射出
        if(Game::getFlameCount()%10==0) {

            for (int i = 0; i<MAX_BOSS_BULLET; i++) {
                if (bullets[i]->getExistFlag() == OFF) {

                    // 弾丸の射出位置を設定
                    bullets[i]->setX(X+50);
                    bullets[i]->setY(Y+53);

                    // 弾丸の射出方向を設定
                    bullets[i]->setVectorX(cos(3*(counter*(PI/180)))); // counter*(PI/180)は角度(弧度法)
                    bullets[i]->setVectorY(sin(3*(counter*(PI/180)))); // 3は角速度
                    
                    // 弾丸の存在フラグをONにする
                    bullets[i]->setExistFlag(ON);
                    break;
                }
            }
        }

        // 弾丸の描画と移動処理
        for(int i=0; i<MAX_BOSS_BULLET; i++) {
            if(bullets[i]->getExistFlag()==ON) {
                bullets[i]->draw();
                bullets[i]->bossBulletMove();
            }
            // 弾丸が画面の外に出たら弾丸の存在フラグをOFFに戻す
            if(bullets[i]->getX()<0 || bullets[i]->getX()>WINDOW_WIDTH ||
               bullets[i]->getY()<0 || bullets[i]->getY()>WINDOW_HEIGHT) {
                bullets[i]->setExistFlag(OFF);
            }
        }

    }
}


// 耐久力を減らす処理をする関数
void Boss::damage() {
    /* プレイヤー弾に当たったら各フラグが反転しているので、
       耐久力を減らして各フラグを元に戻す */
    if(life>0 && existFlag==OFF && hitFlag==ON) {
        life -= 1;
        existFlag = ON;
        hitFlag = OFF;
    }
}


// 爆発処理関数
void Boss::explode() {

    // 耐久力が0になった場合
    if(life==0) {

        timer++;   // タイマーを進める

        // 被弾時の座標を取得
        if(timer==1) {
            collisionX = X;
            collisionY = Y;
        }

        // 爆発エフェクトを描画
        indexNumber = timer/4 % 8;
        DrawRotaGraph(collisionX+64, collisionY+40, 1.5, 0.0, explosions[indexNumber], TRUE) ;

        // 爆発音を再生
        if(CheckSoundMem(explosionSoundHandle)==0) {
            PlaySoundMem(explosionSoundHandle, DX_PLAYTYPE_BACK, TRUE);
        }

        // タイマー作動中もボスが保有する時間は進める
        if(counter<360) {
            counter++;
        }
        if(counter==360) {
            counter = 0;
        }
        
    }
}


// 待機処理関数
void Boss::wait() {
    if(life==0) {
        if(timer==120) {   // 爆発時から2秒経過後
            Game::setScore(Game::getScore()+BOSS_POINT);   // スコアを加算
            Game::setGameState(GAME_CLEAR);   // ゲームクリア画面へ移行
        }
    }
}
