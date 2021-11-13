#ifndef SHOOTING_GAME_BOSS_H
#define SHOOTING_GAME_BOSS_H

#include "dxlib/DxLib.h"
#include<math.h>
#include "character.h"
#include "bullet.h"
#include "define.h"

class Boss : public Character {

    private:
        int vectorX;   // x座標の向き
        
    public:
        Bullet* bullets[MAX_BOSS_BULLET];   // 弾丸格納配列(Gameクラスで呼び出すためにココに定義する)
        Boss();   // コンストラクタ
        ~Boss();   // デストラクタ
        void setVectorX(int direction);   // x座標の向きのセッター
        void draw();   // 描画処理関数
        void move();   // 移動処理関数
        void bulletCreate();   // 弾丸作成関数
        void shot();   // 弾丸射出処理関数
        void damage();   // 耐久力を減らす処理をする関数
        void explode();   // 爆発処理関数
        void wait();   // 待機処理関数
};

#endif
