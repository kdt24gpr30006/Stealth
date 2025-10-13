// ライブラリ読込
#include "Game.h"
#include <memory>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	// 初期化処理
	Game::GetInstance().Init();

	// Init()がfalseで帰ってきたらその時点で終了
	if (Game::GetInstance().Init() == false)
	{
		return -1;
	}

	// ゲームループ
	Game::GetInstance().Loop();

	// 終了処理
	Game::GetInstance().End();


	// ソフトの終了
	return 0;
}