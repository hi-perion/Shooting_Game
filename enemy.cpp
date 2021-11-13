#include "enemy.h"
#include "game.h"

// コンストラクタ
Enemy::Enemy() {
    existFlag = OFF;   // 存在フラグの設定
    counter = 0;   // 敵が保有する時間の初期値の設定
    timer = 0;   // タイマーの初期値の設定
    hitFlag = OFF;   // 衝突フラグの設定
    graphicHandle = LoadGraph("enemy.png");   // グラフィックハンドルの取得
    GetGraphSize(graphicHandle, &width, &height);   // 画像の横幅、高さの取得
    X = ENEMY_SET_POSITION_X;   // x座標の初期値の設定
    Y = ENEMY_SET_POSITION_Y;   // y座標の初期値の設定
    bulletCreate();   // 弾丸作成
    LoadDivGraph("explosion.png", 8, 1, 8, 80, 80, explosions, TRUE); // 分割画像(爆発エフェクト)を配列に格納
    explosionSoundHandle = LoadSoundMem("enemy_explosion.mp3");   // 爆発音の取得
    ChangeVolumeSoundMem(255*50/100, explosionSoundHandle);   // 爆発音の音量を調節
}

// デストラクタ
Enemy::~Enemy() {
    // バレットオブジェクトをすべて破棄
    for(int i=0; i<MAX_ENEMY_BULLET; i++) {
        delete bullets[i];
    }
}

// プレイヤーのx座標のセッター
void Enemy::setPlayerX(int positionX) {
    playerX = positionX;
}

// プレイヤーのy座標のセッター
void Enemy::setPlayerY(int positionY) {
    playerY = positionY;
}


// 描画処理関数
void Enemy::draw() {
    if(existFlag==ON && hitFlag==OFF) {
        
        // 敵を描画
        DrawGraph(X, Y, graphicHandle, TRUE);
        
        // 敵が保有する時間を進める
        if(counter<360) {
            counter++;
        }
        if(counter==360) {
            counter = 0;
        }
        
    }
}


// 移動処理関数
void Enemy::move() {
    if(existFlag==ON && hitFlag==OFF) {
        X -= ENEMY_SPEED;
        Y = (int)(30 + 25*sin((2*PI)/360*counter));
        // 中心位置+振幅*sin(2π/周期*counter)でsin波を表現できる模様
        if(X+width < 0) {
            X = WINDOW_WIDTH;
        }
    }
}


// 爆発処理関数
void Enemy::explode() {

    // プレイヤーまたはプレイヤー本体に衝突した場合
    if(hitFlag==ON) {

        // タイマーを進める
        timer++;

        // プレイヤー弾またはプレイヤー本体と衝突時の座標を取得
        if(timer==1) {
            collisionX = X;
            collisionY = Y;
        }

        // 爆発エフェクトを描画
        indexNumber = timer/4 % 8;
        DrawGraph(collisionX-17, collisionY-18, explosions[indexNumber], TRUE);
        
        // 爆発音を再生
        if(CheckSoundMem(explosionSoundHandle)==0) {
            PlaySoundMem(explosionSoundHandle, DX_PLAYTYPE_BACK, TRUE);
        }
        
        // タイマー作動中も敵が保有する時間は進める
        if(counter<360) {
            counter++;
        }
        if(counter==360) {
            counter = 0;
        }

    }
}


// 待機処理関数
void Enemy::wait() {
    if(hitFlag==ON) {

        // 自身(敵)が保有するすべての弾の存在フラグをOFF
        for(int i=0; i<MAX_ENEMY_BULLET; i++) {
            this->bullets[i]->setExistFlag(OFF);
        }
        
        if(timer==30) {   // 爆発時から0.5秒経過後
            hitFlag = OFF;   // 衝突フラグをOFFに戻す
            timer = 0;   // タイマーをリセット
            X = ENEMY_SET_POSITION_X;   // 復活後の敵のx座標の位置
            Y = ENEMY_SET_POSITION_Y;   // 復活後の敵のy座標の位置
        }
    }
}

// 弾丸作成関数
void Enemy::bulletCreate() {
    // 弾丸を作成して配列に格納
    for(int i=0; i<MAX_ENEMY_BULLET; i++) {
        bullets[i] = new Bullet("enemy_bullet.png");   // 弾丸作成
    }
}


// 弾丸射出処理関数
void Enemy::shot() {

    if(existFlag==ON && hitFlag==OFF) {

        // 0.5秒ごとに弾丸を射出
        if(Game::getFlameCount()%30==0) {
            
            for (int i = 0; i<MAX_ENEMY_BULLET; i++) {
                if (bullets[i]->getExistFlag() == OFF) {
                    
                    // 弾丸の射出位置を設定
                    bullets[i]->setX(X+9);
                    bullets[i]->setY(Y+17);
                    
                    // 弾丸射出時のプレイヤーと敵の位置を設定
                    bullets[i]->setFixedPlayerX(playerX);
                    bullets[i]->setFixedPlayerY(playerY);
                    bullets[i]->setFixedEnemyX(X);
                    bullets[i]->setFixedEnemyY(Y);

                    // 弾丸の存在フラグをONにする
                    bullets[i]->setExistFlag(ON);
                    break;
                }
            }
        }

        // 弾丸の描画と移動処理
        for(int i=0; i<MAX_ENEMY_BULLET; i++) {
            if(bullets[i]->getExistFlag()==ON) {
                bullets[i]->draw();
                bullets[i]->enemyBulletMove();
            }
            // 弾丸が画面の外に出たら弾丸の存在フラグをOFFに戻す
            if(bullets[i]->getX()<0 || bullets[i]->getX()>WINDOW_WIDTH ||
               bullets[i]->getY()<0 || bullets[i]->getY()>WINDOW_HEIGHT) {
                bullets[i]->setExistFlag(OFF);
            }
        }
        
    }
}
