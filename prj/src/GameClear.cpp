#include "GameClear.h"
#include "TitleScene.h"
#include "WinMain.h"
#include <DxLib.h>

void GameClearScene::Init()
{

}

void GameClearScene::Update()
{
	// エンターキーが押されたらタイトルシーンへ移行
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		manager->ChengeScene(std::make_shared<TitleScene>(manager));
	}
}

void GameClearScene::Render()
{
	SetFontSize(48);
	int strWidth = GetDrawStringWidth("Game Clear", -1) / 2;
	DrawString(WINDOW_W / 2 - strWidth, 200, "Game Clear", GetColor(0, 255, 0));
	SetFontSize(24);
	strWidth = GetDrawStringWidth("Press Enter to Title", -1) / 2;
	DrawString(WINDOW_W / 2 - strWidth, 400, "Press Enter to Title", GetColor(255, 255, 255));
}