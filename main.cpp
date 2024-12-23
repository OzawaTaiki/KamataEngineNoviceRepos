#include <Novice.h>

#include "SceneManager.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "GameClearScene.h"
#include "InputManager.h"

const char kWindowTitle[] = "LE2A_06_オザワ_タイキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

    SceneManager* pSceneManager = SceneManager::GetInstance();
    pSceneManager->RegisterScene("Game", GameScene::Create);
    pSceneManager->RegisterScene("Title", TitleScene::Create);
    pSceneManager->RegisterScene("GameClear", GameClearScene::Create);



    pSceneManager->Initialize("Title");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
        InputManager::GetInstance()->Update();

		///
		/// ↓更新処理ここから
		///

		pSceneManager->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		pSceneManager->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();
		pSceneManager->ChangeScene();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
