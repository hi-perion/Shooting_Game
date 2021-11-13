#include "bullet.h"

// コンストラクタ
Bullet::Bullet(string imageFilePath) {
    existFlag = OFF;   // 存在フラグの設定
    graphicHandle = LoadGraph(imageFilePath.c_str());   // グラフィックハンドルの取得
    GetGraphSize(graphicHandle, &width, &height);   // 画像の横幅、高さの取得
}

// デストラクタ
Bullet::~Bullet() {}

// 存在フラグのゲッター
int Bullet::getExistFlag() {
    return existFlag;
}

// 存在フラグのセッター
void Bullet::setExistFlag(int state) {
    existFlag = state;
}

// x座標のゲッター
int Bullet::getX() {
    return X;
}

// x座標のセッター
void Bullet::setX(int positionX) {
    X = positionX;
}

// y座標のゲッター
int Bullet::getY() {
    return Y;
}

// y座標のセッター
void Bullet::setY(int positionY) {
    Y = positionY;
}

// x座標の向きのセッター
void Bullet::setVectorX(double directionX) {
    vectorX = directionX;
}

// y座標の向きのセッター
void Bullet::setVectorY(double directionY) {
    vectorY = directionY;
}

// 敵(ボス)弾射出時のプレイヤーのx座標のセッター
void Bullet::setFixedPlayerX(int playerX) {
    fixedPlayerX = playerX;
}

// 敵(ボス)弾射出時のプレイヤーのy座標のセッター
void Bullet::setFixedPlayerY(int playerY) {
    fixedPlayerY = playerY;
}

// 敵弾射出時の敵のx座標のセッター
void Bullet::setFixedEnemyX(int enemyX) {
    fixedEnemyX = enemyX;
}

// 敵弾射出時の敵のy座標のセッター
void Bullet::setFixedEnemyY(int enemyY) {
    fixedEnemyY = enemyY;
}

// 描画処理関数
void Bullet::draw() {
    DrawGraph(X, Y, graphicHandle, TRUE);
}

// プレイヤー弾の移動処理関数
void Bullet::playerBulletMove() {
    Y -= PLAYER_BULLET_SPEED;
}


// 物体との衝突処理関数
void Bullet::hit(int targetX, int targetY,
                  int targetWidth, int targetHeight,
                  int* pTargetExistFlag, int* pTargetHitFlag) {
    
    // 物体と衝突した場合
    if(((X > targetX && X < targetX+targetWidth) || (targetX > X && targetX < X+width)) &&
       ((Y > targetY && Y < targetY+targetHeight) || (targetY > Y && targetY < Y+height))) {
        existFlag = OFF;   // 自身(弾丸)の存在フラグをOFFにする
        *pTargetExistFlag = OFF;   // 対象(物体)の存在フラグをOFFにする
        *pTargetHitFlag = ON;   // 対象(物体)の衝突フラグをONにする
    }
    
}


// 敵弾の移動処理関数
void Bullet::enemyBulletMove(){
    
    // 敵弾の移動量を計算
    distanceX = (fixedPlayerX+17) - (fixedEnemyX+17);
    distanceY = (fixedPlayerY+19) - (fixedEnemyY+18);
    distance = sqrt(distanceX*distanceX + distanceY*distanceY);
    enemyBulletMoveAmountX = distanceX/distance*ENEMY_BULLET_SPEED;
    enemyBulletMoveAmountY = distanceY/distance*ENEMY_BULLET_SPEED;
    
    // 敵弾の移動処理
    X += enemyBulletMoveAmountX;
    Y += enemyBulletMoveAmountY;
}


// ボス弾の移動処理関数
void Bullet::bossBulletMove() {
    X += vectorX * BOSS_BULLET_SPEED;
    Y += vectorY * BOSS_BULLET_SPEED;
}
