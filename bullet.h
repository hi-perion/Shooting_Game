#ifndef SHOOTING_GAME_BULLET_H
#define SHOOTING_GAME_BULLET_H

#include "dxlib/DxLib.h"
#include <iostream>
#include<math.h>
#include "define.h"

using namespace std;

class Bullet {
    
    private:
        int graphicHandle;   // グラフィックハンドル
        int existFlag;   // 存在フラグ
        int X;   // x座標
        int Y;   // y座標
        double vectorX;   // x座標の向き
        double vectorY;   // y座標の向き
        int width;   // 画像の横幅
        int height;   // 画像の高さ
        int fixedPlayerX;   // 敵弾射出時のプレイヤーのx座標
        int fixedPlayerY;   // 敵弾射出時のプレイヤーのy座標
        int fixedEnemyX;   // 敵弾射出時の敵のx座標
        int fixedEnemyY;   // 敵弾射出時の敵のy座標
        int distanceX;   // 敵とプレイヤーのx座標の距離
        int distanceY;   // 敵とプレイヤーのy座標の距離
        double distance;  // 敵とプレイヤーの距離
        double enemyBulletMoveAmountX;   // 敵弾のx座標の移動量
        double enemyBulletMoveAmountY;   // 敵弾のy座標の移動量

    public:
        Bullet(string imageFilePath);   // コンストラクタ
        ~Bullet();   // デストラクタ
        int getExistFlag();   // 存在フラグのゲッター
        void setExistFlag(int state);   // 存在フラグのセッター
        int getX();   // x座標のゲッター
        void setX(int positionX);   // x座標のセッター
        int getY();   // y座標のゲッター
        void setY(int positionY);   // y座標のセッター
        void setVectorX(double directionX);   // x座標の向きのセッター
        void setVectorY(double directionY);   // y座標の向きのセッター
        void draw();   // 描画処理関数
        void setFixedPlayerX(int playerX);   // 敵弾射出時のプレイヤーのx座標のセッター
        void setFixedPlayerY(int playerY);   // 敵弾射出時のプレイヤーのy座標のセッター
        void setFixedEnemyX(int enemyX);   // 敵弾射出時の敵のx座標のセッター
        void setFixedEnemyY(int enemyY);   // 敵弾射出時の敵のy座標のセッター
        void playerBulletMove();   // プレイヤー弾の移動処理関数
        void enemyBulletMove();   // 敵弾の移動処理関数
        void bossBulletMove();   // ボス弾の移動処理関数

        // 物体との衝突処理関数
        void hit(int targetX, int targetY, 
                  int targetWidth, int targetHeight,
                  int* pTargetExistFlag, int* pTargetHitFlag);
};

#endif
