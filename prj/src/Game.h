#pragma once

#include <ctime>		// 標準C ライブラリ ヘッダー <time.h> をインクルードし、関連する名前を std 名前空間に追加します。
#include "DxLib.h"		// DxLib
#include "CheckInput.h"
#include "WinMain.h"

// ゲーム関係
class Game
{
	// 入力処理関数
	void input();

	// 画面更新関数
	void render();

	// 音声再生処理関数
	void sound();

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

	virtual ~Game()
	{

	}
};