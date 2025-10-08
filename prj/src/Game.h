#pragma once

#include <ctime>		// 標準C ライブラリ ヘッダー <time.h> をインクルードし、関連する名前を std 名前空間に追加します。
#include "DxLib.h"		// DxLib
#include "CheckInput.h"

//	定数の宣言
const int WINDOW_W = 1280;	// 画面サイズ　横
const int WINDOW_H = 720;	// 画面サイズ　縦

/// <summary>
/// ゲーム関係
/// </summary>
class Game
{
	/// <summary>
	/// 入力処理関数
	/// </summary>
	void input();

	/// <summary>
	/// 画面更新関数
	/// </summary>
	void render();

	/// <summary>
	/// 音声再生処理関数
	/// </summary>
	void sound();

	Game() {}
public:

	// コピー代入禁止
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	/// <summary>
	/// インスタンスを返す
	/// </summary>
	/// <returns></returns>
	static Game& GetInstance()
	{
		static Game instance;
		return instance;
	}

	/// <summary>
	/// 初期化関数
	/// </summary>
	/// <returns><成功:true, 失敗:false/returns>
	bool Init();

	/// <summary>
	/// 更新関数
	/// </summary>
	void Loop();

	/// <summary>
	/// 終了関数
	/// </summary>
	void End();

	virtual ~Game()
	{

	}
};