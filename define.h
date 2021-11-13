#ifndef SHOOTING_GAME_DEFINE_H
#define SHOOTING_GAME_DEFINE_H

// ON、OFF状態
#define ON  1
#define OFF 0

// 左右方向
#define RIGHT_DIRECTION 1
#define LEFT_DIRECTION -1

#define PI 3.141593   // 円周率

#define PLAYER_SET_POSITION_X 303   // プレイヤーのx座標の初期位置
#define PLAYER_SET_POSITION_Y 400   // プレイヤーのy座標の初期位置
#define PLAYER_SPEED 3   // プレイヤーの速度
#define MAX_PLAYER_LIFE 5   // プレイヤーの最大残機
#define MAX_PLAYER_BULLET 5   // プレイヤーの最大弾数
#define PLAYER_BULLET_SPEED 5   // プレイヤー弾の速度

#define ENEMY_SET_POSITION_X 640   // 敵のx座標の初期位置
#define ENEMY_SET_POSITION_Y 50   // 敵のy座標の初期位置
#define ENEMY_SPEED 3   // 敵の速度
#define MAX_ENEMY 3   // 敵の最大数
#define MAX_ENEMY_BULLET 2   // 敵の最大弾数
#define ENEMY_BULLET_SPEED 4   // 敵弾の速度
#define ENEMY_POINT 100   // 敵の得点
#define ENEMY_LIMIT 15   // 敵の撃墜数の上限値

#define BOSS_SET_POSITION_X 640   // ボスのx座標の初期位置
#define BOSS_SET_POSITION_Y 25   // ボスのy座標の初期位置
#define BOSS_SPEED 2   // ボスの速度
#define BOSS_BULLET_SPEED 4   // ボス弾の速度
#define MAX_BOSS_LIFE 10   // ボスの耐久力
#define MAX_BOSS_BULLET 10   // ボスの最大弾数
#define BOSS_POINT 10000   // ボスの得点

#define WINDOW_WIDTH  640   // ウィンドウの横幅
#define WINDOW_HEIGHT 480   // ウィンドウの高さ

// ゲームの進行状態
#define GAME_RESET  0   // ゲームリセット
#define GAME_START  1   // ゲームスタート
#define GAME_PLAY  2   // ゲームプレイ
#define GAME_OVER  3   // ゲームオーバー
#define GAME_CLEAR  4   // ゲームクリア

#endif
