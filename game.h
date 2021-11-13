#ifndef SHOOTING_GAME_GAME_H
#define SHOOTING_GAME_GAME_H

#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "bullet.h"

class Game {

    private:
        static int gameState;   // ゲームの進行状態
        static int flameCount;  // 描画回数
        static int score;   // スコア
        int gameStartImage;   // ゲームスタート画像
        int gameOverImage;   // ゲームオーバー画像
        int gameClearImage;   // ゲームクリア画像
        int backgroundImage;   // 背景画像
        int backgroundSoundHandle;   // バックグラウンドミュージック
        int gameOverSoundHandle;   // ゲームオーバー音
        int gameClearSoundHandle;   // ゲームクリア音
        int endSoundFlag;   // 終了音(ゲームオーバー音かゲームクリア音)のフラグ
        Player* player;   // プレイヤーオブジェクト
        Enemy* enemies[MAX_ENEMY];   // 敵オブジェクト格納配列
        Boss* boss;   // ボスオブジェクト
        int enemyCount;   // 敵の撃墜数
        int backgroundY;   // 背景画像のy座標
        
    public:
        Game();   // コンストラクタ
        ~Game();   // デストラクタ
        static void setGameState(int number);   // ゲームの進行状態のセッター
        static int getFlameCount();    // 描画回数のゲッター
        static int getScore();   // スコアのゲッター
        static void setScore(int number);   // スコアのセッター
        void control();   // ゲームの進行状態を管理する関数
        void gameReset();   // ゲーム状態を初期化する関数
        void gameStart();   // ゲームスタート画面表示関数
        void gamePlay();   // 連続描画するときの処理
        void gameOver();   // ゲームオーバー画面表示関数
        void gameClear();   // ゲームクリア画面表示関数
        void enemyCreate();   // 敵オブジェクト作成関数
        void backgroundDraw();   // 背景描画関数
};

#endif
