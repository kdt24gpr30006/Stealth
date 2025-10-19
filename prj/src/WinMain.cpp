// ライブラリ読込
#include "Game.h"
#include <memory>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	Game& game = Game::GetInstance(); // シングルトンインスタンス生成

	// 初期化処理
	if (game.Init() == false)
	{
		// Init()がfalseで帰ってきたらその時点で終了
		return -1;
	}

	// ゲームループ
	game.Loop();

	// 終了処理
	game.End();


	// ソフトの終了
	return 0;
}