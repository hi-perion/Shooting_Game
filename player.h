#ifndef SHOOTING_GAME_PLAYER_H
#define SHOOTING_GAME_PLAYER_H

#include "dxlib/DxLib.h"
#include "character.h"
#include "bullet.h"
#include "define.h"

class Player : public Character {

    private:
        float moveCoefficient;   // 移動係数
        int shotButtonFlag;   // ショットボタンフラグ
        int shotSoundHandle;   // ショット音のサウンドハンドル
        
    public:
        Bullet* bullets[MAX_PLAYER_BULLET];   // 弾丸格納配列(Gameクラスで呼び出すためにココに定義する)
        Player();   // コンストラクタ
        ~Player();   // デストラクタ
        void draw();   // 描画処理関数
        void move();   // 移動処理関数
        void bulletCreate();   // 弾丸作成関数
        void shot();   // 弾丸射出処理関数
        void die();   // 残機を減らす処理をする関数
        void explode();   // 爆発処理関数
        void wait();   // 待機処理関数
        void gameOver();   // ゲームオーバー(残機0)時の処理関数

        // 敵またはボスとの衝突処理関数
        void crash(int targetX, int targetY,
                    int targetWidth, int targetHeight,
                    int* pTargetExistFlag, int* pTargetHitFlag);
};

#endif
