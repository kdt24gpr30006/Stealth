#pragma once

#include <ctime>		// 標準C ライブラリ ヘッダー <time.h> をインクルードし、関連する名前を std 名前空間に追加します。
#include "DxLib.h"		// DxLib
#include "CheckInput.h"
#include "WinMain.h"
#include "GameScene.h"

// ゲーム関係
class Game
{
	// ゲームシーン
	GameScene& gameScene = GameScene::GetInstance();
	// インプット
	CheckInputKey& inputKey = CheckInputKey::GetInstance();

	// 入力処理関数
	void input();

	// 画面更新関数
	void GameLoop();

	Game() {}
public:

	// コピー代入禁止
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	// インスタンスを返す
	static Game& GetInstance()
	{
		static Game instance;
		return instance;
	}

	// 初期化関数
	bool Init();

	// 更新関数
	void Loop();

	// 終了関数
	void End();
};