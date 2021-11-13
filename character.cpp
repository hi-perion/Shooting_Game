#include "character.h"

// コンストラクタ
Character::Character() {}

// デストラクタ
Character::~Character() {}

// 存在フラグのゲッター
int Character::getExistFlag() {
    return existFlag;
}

// 存在フラグのポインタのゲッター
int* Character::pGetExistFlag() {
    pExistFlag = &existFlag;
    return pExistFlag;
}

// 存在フラグのセッター
void Character::setExistFlag(int state) {
    existFlag = state;
}

// 衝突フラグのゲッター
int Character::getHitFlag() {
    return hitFlag;
}

// 衝突フラグのポインタゲッター
int* Character::pGetHitFlag() {
    pHitFlag = &hitFlag;
    return pHitFlag;
}

// 衝突フラグのセッター
void Character::setHitFlag(int state) {
    hitFlag = state;
}

// オブジェクトが保有する時間のセッター
void Character::setCounter(int number) {
    counter = number;
}

// オブジェクトが保有するタイマーのセッター
void Character::setTimer(int number) {
    timer = number;
}

// 残機または耐久力のゲッター
int Character::getLife() {
    return life;
}

// 残機または耐久力のセッター
void Character::setLife(int number) {
    life = number;
}

// x座標のゲッター
int Character::getX() {
    return X;
}

// x座標のセッター
void Character::setX(int positionX) {
    X = positionX;
}

// y座標のゲッター
int Character::getY() {
    return Y;
}

// y座標のセッター
void Character::setY(int positionY) {
    Y = positionY;
}

// 画像の横幅のゲッター
int Character::getWidth() {
    return width;
}

// 画像の高さのゲッター
int Character::getHeight() {
    return height;
}
