#include "game.h"

// ゲームの進行状態の初期化
int Game::gameState = GAME_START;

// 描画回数の初期化
int Game::flameCount = 0;

// スコアの初期化
int Game::score = 0;

// コンストラクタ
Game::Game() {
    player = new Player();   // プレイヤーオブジェクトを作成
    enemyCreate();   // 敵オブジェクトを作成
    boss = new Boss();   // ボスオブジェクトを作成
    enemyCount = 0;   // 敵の撃墜数の初期値を設定
    backgroundY = 0;   // 背景画像のy座標の初期値を設定
    gameStartImage = LoadGraph("game_start.jpg");   // ゲームスタート画像の取得
    gameOverImage = LoadGraph("game_over.jpg");   // ゲームオーバー画像の取得
    gameClearImage = LoadGraph("game_clear.jpg");   // ゲームクリア画像の取得
    backgroundImage = LoadGraph("background.png");   // 背景画像の取得
    backgroundSoundHandle = LoadSoundMem("background_music.mp3");   // バックグラウンドミュージックの取得
    ChangeVolumeSoundMem(255*50/100, backgroundSoundHandle);   // バックグラウンドミュージックの音量を調節
    gameOverSoundHandle = LoadSoundMem("game_over.mp3");   // ゲームオーバー音の取得
    ChangeVolumeSoundMem(255*65/100, gameOverSoundHandle);   // ゲームオーバー音の音量を調節
    gameClearSoundHandle = LoadSoundMem("game_clear.mp3");   // ゲームクリア音の取得
    ChangeVolumeSoundMem(255*35/100, gameClearSoundHandle);   // ゲームクリア音の音量を調節
    endSoundFlag = OFF;   // 終了音(ゲームオーバー音かゲームクリア音)のフラグの設定
}

// デストラクタ
Game::~Game() {
    // 各オブジェクトを破棄
    delete player;
    delete boss;
    for(int i=0; i<MAX_ENEMY; i++) {
        delete enemies[i];
    }
}

// ゲームの進行状態のセッター
void Game::setGameState(int number) {
    gameState = number;
}

// 描画回数のゲッター
int Game::getFlameCount() {
    return flameCount;
}

// スコアのゲッター
int Game::getScore() {
    return score;
}

// スコアのセッター
void Game::setScore(int number) {
    score = number;
}

// 敵オブジェクト作成関数
void Game::enemyCreate() {
    // 敵を作成して配列に格納
    for(int i=0; i<MAX_ENEMY; i++) {
        enemies[i] = new Enemy();   // 敵オブジェクト作成
    }
}

// 背景描画関数
void Game::backgroundDraw() {
    backgroundY++;
    if(backgroundY>WINDOW_HEIGHT) {
        backgroundY = 0;
    }
    DrawGraph(0, backgroundY, backgroundImage, TRUE);
    DrawGraph(0, backgroundY-WINDOW_HEIGHT, backgroundImage, TRUE);
}


// 連続描画するときの処理
void Game::gamePlay() {
    
    // 描画回数をカウント(60回(1秒)でリセット)
    flameCount++;
    if(flameCount==60) {   
        flameCount = 0;
    }

    // 背景を描画
    backgroundDraw();

    // バックグラウンドミュージックを再生
    if(CheckSoundMem(backgroundSoundHandle)==0) {
        PlaySoundMem(backgroundSoundHandle, DX_PLAYTYPE_LOOP, TRUE);
    }
    
    player->draw();   // プレイヤーの描画処理
    player->move();   // プレイヤーの移動処理
    player->shot();   // プレイヤー弾の射出処理
    player->die();   // プレイヤーの残機を減らす処理
    player->explode();   // プレイヤーの爆発処理関数
    player->wait();   // プレイヤーの待機処理
    player->gameOver();   // ゲームオーバー(残機0)時の処理関数
    
    // 起動直後に敵を0.5秒ごとに出現させるための処理
    for(int i=0; i<MAX_ENEMY; i++) {
        if(enemies[i]->getExistFlag()==OFF && enemies[i]->getHitFlag()==OFF &&
            enemyCount<=ENEMY_LIMIT && flameCount%30==0) {
            enemies[i]->setExistFlag(ON);
            break;
        }
    }
    
    // 敵の処理
    for(int i=0; i<MAX_ENEMY; i++) {
        
        enemies[i]->draw();   // 敵の描画処理
        enemies[i]->move();   // 敵の移動処理
        
        // プレイヤーの座標を取得
        enemies[i]->setPlayerX(player->getX());
        enemies[i]->setPlayerY(player->getY());
        
        enemies[i]->shot();   // 敵弾の射出処理 
        enemies[i]->explode();   // 敵の爆発処理
        enemies[i]->wait();   // 敵の待機処理
        
        // 各物体同士の衝突処理
        if(enemies[i]->getExistFlag()==ON) {
            
            // プレイヤーの射出した弾と敵の衝突処理
            for(int j=0; j<MAX_PLAYER_BULLET; j++) {
                if(player->bullets[j]->getExistFlag()==ON) {
                    player->bullets[j]->hit(enemies[i]->getX(), enemies[i]->getY(),
                                            enemies[i]->getWidth(), enemies[i]->getHeight(),
                                            enemies[i]->pGetExistFlag(), enemies[i]->pGetHitFlag());
                    
                    if(enemies[i]->getExistFlag()==OFF) {
                        enemyCount++;   // 敵の撃墜数を加算
                        score += ENEMY_POINT;   // スコアを加算
                    }
                }
            }
            
            // 敵の射出した弾とプレイヤーの衝突処理
            for(int k=0; k<MAX_ENEMY_BULLET; k++) {
                if(enemies[i]->bullets[k]->getExistFlag()==ON) {
                    enemies[i]->bullets[k]->hit(player->getX(), player->getY(),
                                                player->getWidth(), player->getHeight(),
                                                player->pGetExistFlag(), player->pGetHitFlag());
                }
            }
            
            // プレイヤーと敵の衝突処理
            player->crash(enemies[i]->getX(), enemies[i]->getY(),
                          enemies[i]->getWidth(), enemies[i]->getHeight(),
                          enemies[i]->pGetExistFlag(), enemies[i]->pGetHitFlag());
        }
        
    }

    // 指定数以上の敵を撃墜した場合
    if(enemyCount>=ENEMY_LIMIT){
        
        boss->draw();   // ボスの描画処理
        boss->move();   // ボスの移動処理
        boss->shot();   // ボス弾射出処理

        // プレイヤーの射出した弾とボスの衝突処理
        for(int i=0; i<MAX_PLAYER_BULLET; i++) {
            if(player->bullets[i]->getExistFlag()==ON) {
                player->bullets[i]->hit(boss->getX(), boss->getY(),
                                        boss->getWidth(), boss->getHeight(),
                                        boss->pGetExistFlag(), boss->pGetHitFlag());
            }
        }

        // ボスの射出した弾とプレイヤーの衝突処理
        for(int i=0; i<MAX_BOSS_BULLET; i++) {
            if(boss->bullets[i]->getExistFlag()==ON) {
                boss->bullets[i]->hit(player->getX(), player->getY(),
                                      player->getWidth(), player->getHeight(),
                                      player->pGetExistFlag(), player->pGetHitFlag());
            }
        }

        // プレイヤーとボスの衝突処理
        player->crash(boss->getX(), boss->getY(),
                      boss->getWidth(), boss->getHeight(),
                      boss->pGetExistFlag(), boss->pGetHitFlag());
        
        boss->damage();   // ボスのダメージ処理
        boss->explode();   // ボスの爆発処理
        boss->wait();   // ボスの待機処理
    }

    // プレイヤーのライフを表示
    DrawFormatString(10, 7, GetColor(255,255,255), "LIFE %d", player->getLife());

    // スコアを表示
    DrawFormatString(530, 7, GetColor(255,255,255), "score %d", score);
}


// ゲームの進行状態をリセットする関数
void Game::gameReset() {
    
    flameCount = 0;   // フレームカウントをリセット
    score = 0;   // スコアをリセット
    enemyCount = 0;   // 敵の撃墜数をリセット
    endSoundFlag = OFF;   // 終了音フラグをOFF
    
    player->setExistFlag(ON);   // プレイヤーの存在フラグをON
    player->setHitFlag(OFF);   // プレイヤーの衝突フラグをOFF
    player->setTimer(0);   // プレイヤーが保有するタイマーをリセット
    player->setLife(MAX_PLAYER_LIFE);   // プレイヤーの残機をリセット

    // プレイヤー弾の存在フラグをOFF
    for(int i=0; i<MAX_PLAYER_BULLET; i++) {
        player->bullets[i]->setExistFlag(OFF);
    }
    
    // プレイヤーの座標を初期位置に戻す
    player->setX(PLAYER_SET_POSITION_X);
    player->setY(PLAYER_SET_POSITION_Y);
    
    // 敵のパラメーターをリセット
    for(int i=0; i<MAX_ENEMY; i++) {
        
        enemies[i]->setExistFlag(OFF);   // 敵の存在フラグをOFF
        enemies[i]->setHitFlag(OFF);   // 敵の衝突フラグをOFF
        enemies[i]->setCounter(0);   // 敵が保有する時間をリセット
        enemies[i]->setTimer(0);   // 敵が保有するタイマーをリセット
        
        // 敵の座標を初期位置に戻す
        enemies[i]->setX(ENEMY_SET_POSITION_X);
        enemies[i]->setY(ENEMY_SET_POSITION_Y);
        
        // 敵弾の存在フラグをOFF
        for(int k=0; k<MAX_ENEMY_BULLET; k++) {
            enemies[i]->bullets[k]->setExistFlag(OFF);
        }
    }
    
    boss->setExistFlag(ON);   // ボスの存在フラグをON
    boss->setHitFlag(OFF);   // ボスの衝突フラグをOFF
    boss->setCounter(0);   // ボスが保有する時間をリセット
    boss->setTimer(0);   // ボスが保有するタイマーをリセット
    boss->setLife(MAX_PLAYER_LIFE);   // ボスの耐久力をリセット

    // ボス弾の存在フラグをOFF
    for(int i=0; i<MAX_BOSS_BULLET; i++) {
        boss->bullets[i]->setExistFlag(OFF);
    }

    // ボスの座標を初期位置に戻す
    boss->setX(BOSS_SET_POSITION_X);
    boss->setY(BOSS_SET_POSITION_Y);
    boss->setVectorX(LEFT_DIRECTION);   // ボスのx座標の向きを元に戻す
    
    gameState = GAME_START;   // スタート画面へ移行
}


// ゲームスタート画面表示関数
void Game::gameStart() {
    DrawGraph(0, 0, gameStartImage, TRUE);
    DrawFormatString(295, 200, GetColor(255,255,255), "START");
    DrawFormatString(260, 290, GetColor(255,255,255), "Shot is Z key.");
    DrawFormatString(267, 400, GetColor(255,255,255), "PRESS S KEY");
    if(CheckHitKey(KEY_INPUT_S)==ON) {
        gameState = GAME_PLAY;   // ゲームプレイ画面へ移行
    }
}


// ゲームオーバー画面表示関数
void Game::gameOver() {
    
    // バックグラウンドミュージックを停止して、ゲームオーバー音を再生
    if(endSoundFlag==OFF) {
        StopSoundMem(backgroundSoundHandle);
        PlaySoundMem(gameOverSoundHandle, DX_PLAYTYPE_BACK, TRUE);
        endSoundFlag = ON;
    }
    
    // 結果を表示
    DrawGraph(0, 0, gameOverImage, TRUE);
    DrawFormatString(285, 150, GetColor(255,255,255), "GAME OVER");
    DrawFormatString(280, 270, GetColor(255,255,255), "score %d", score);
    
    // リセット処理へ移行
    DrawFormatString(273, 400, GetColor(255,255,255), "PRESS E KEY");
    if(CheckHitKey(KEY_INPUT_E)==ON) {
        gameState = GAME_RESET;
    }
    
}


// ゲームクリア画面表示関数
void Game::gameClear() {
    
    // バックグラウンドミュージックを停止して、ゲームクリア音を再生
    if(endSoundFlag==OFF) {
        StopSoundMem(backgroundSoundHandle);
        PlaySoundMem(gameClearSoundHandle, DX_PLAYTYPE_BACK, TRUE);
        endSoundFlag = ON;
    }

    // 結果を表示
    DrawGraph(0, 0, gameClearImage, TRUE);
    DrawFormatString(295, 200, GetColor(255,255,255), "CLEAR");
    DrawFormatString(267, 290, GetColor(255,255,255), "score %d", score);

    // リセット処理へ移行
    DrawFormatString(267, 400, GetColor(255,255,255), "PRESS C KEY");
    if(CheckHitKey(KEY_INPUT_C)==ON) {
        gameState = GAME_RESET;   // リセット処理へ移行
    }
    
}


// ゲームの進行状態を管理する関数
void Game::control() {
    
    switch(gameState) {
        case GAME_RESET:
            gameReset();
            break;
        case GAME_START:
            gameStart();
            break;
        case GAME_PLAY:
            gamePlay();
            break;
        case GAME_OVER:
            gameOver();
            break;
        case GAME_CLEAR:
            gameClear();
            break;
        default:
            break;
    }

}
