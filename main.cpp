#include "dxlib/DxLib.h"
#include "game.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    // ウィンドウタイトル
    SetMainWindowText("Shooting Game");
    
    // ウィンドウサイズの指定
    ChangeWindowMode(TRUE);
    
    // DXライブラリの初期化処理
    if(DxLib_Init() == -1) return -1;
    
    // 描画先を裏画面に設定
    SetDrawScreen(DX_SCREEN_BACK);
    
    // ゲームオブジェクトの作成
    Game* game = new Game();
    
    // 連続描画処理
    while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0) {
        game->control();
    }
    
    // ゲームオブジェクトの破棄
    delete game;
    
    // DXライブラリの終了処理
    DxLib_End();
    
    // プログラム(WinMain関数)の終了処理
    return 0;
}
