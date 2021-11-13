#ifndef SHOOTING_GAME_ENEMY_H
#define SHOOTING_GAME_ENEMY_H

#include "dxlib/DxLib.h"
#include<math.h>
#include "character.h"
#include "bullet.h"
#include "define.h"

class Enemy : public Character {
    
    private:
        int playerX;   // プレイヤーのx座標
        int playerY;   // プレイヤーのy座標
        
    public:
        Bullet* bullets[MAX_ENEMY_BULLET];   // 弾丸格納配列(Gameクラスで呼び出すためにココに定義する)
        Enemy();   // コンストラクタ
        ~Enemy();   // デストラクタ
        void setPlayerX(int positionX);   // プレイヤーのx座標のセッター
        void setPlayerY(int positionY);   // プレイヤーのy座標のセッター
        void draw();   // 描画処理関数
        void move();   // 移動処理関数
        void explode();   // 爆発処理関数
        void wait();   // 待機処理関数
        void bulletCreate();   // 弾丸作成関数
        void shot();   // 弾丸射出処理関数
};

#endif
