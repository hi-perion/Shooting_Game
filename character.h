#ifndef SHOOTING_GAME_CHARACTER_H
#define SHOOTING_GAME_CHARACTER_H

class Character {

    protected:
        int graphicHandle;   // グラフィックハンドル
        int explosionSoundHandle;   //爆発音のサウンドハンドル 
        int existFlag;   // 存在フラグ
        int* pExistFlag;   // 存在フラグのポインタ
        int hitFlag;   // 衝突フラグ
        int* pHitFlag;   // 衝突フラグのポインタ
        int counter;   // オブジェクトが保有する時間
        int timer;   // オブジェクトが保有するタイマー
        int life;   // 残機または耐久力
        int X;   // x座標
        int Y;   // y座標
        int width;   // 画像の横幅
        int height;   // 画像の高さ
        int collisionX;   // 対象と衝突時のx座標の位置
        int collisionY;   // 対象と衝突時のy座標の位置
        int explosions[8];   // 分割画像(爆発エフェクト)を格納するための配列
        int indexNumber;   // 爆発画像配列のインデックス番号の指定に必要になる変数

    public:
        Character();   // コンストラクタ
        virtual ~Character();   // デストラクタ
        int getExistFlag();   // 存在フラグのゲッター
        int* pGetExistFlag();   // 存在フラグのポインタのゲッター
        void setExistFlag(int state);   // 存在フラグのセッター
        int getHitFlag();   // 衝突フラグのゲッター
        int* pGetHitFlag();   // 衝突フラグのポインタゲッター
        void setHitFlag(int state);   // 衝突フラグのセッター
        void setCounter(int number);   // オブジェクトが保有する時間のセッター
        void setTimer(int number);   // オブジェクトが保有するタイマーのセッター
        int getLife();   // 残機または耐久力のゲッター
        void setLife(int number);   // 残機または耐久力のセッター
        int getX();   // x座標のゲッター
        void setX(int positionX);   // x座標のセッター
        int getY();   // y座標のゲッター
        void setY(int positionY);   // y座標のセッター
        int getWidth();   // 画像の横幅のゲッター
        int getHeight();   // 画像の高さのゲッター
        virtual void draw() = 0;   // 描画処理関数
        virtual void move() = 0;   // 移動処理関数
        virtual void bulletCreate() = 0;   // 弾丸作成関数
        virtual void shot() = 0;   // 弾丸射出処理関数
        virtual void explode() = 0;   // 爆発処理関数
        virtual void wait() = 0;   // 待機処理関数
};

#endif
