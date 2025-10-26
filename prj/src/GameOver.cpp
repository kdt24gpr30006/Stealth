#include "GameOver.h"
#include "TitleScene.h"
#include "WinMain.h"
#include <DxLib.h>

void GameOverScene::Init()
{

}

void GameOverScene::Update()
{
	// エンターキーが押されたらタイトルシーンへ移行
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		manager->ChengeScene(std::make_shared<TitleScene>(manager));
	}
}

void GameOverScene::Render()
{
	SetFontSize(48);
	int strWidth = GetDrawStringWidth("Game Over", -1) / 2;
	DrawString(WINDOW_W / 2 - strWidth, 200, "Game Over", GetColor(255, 0, 0));
	SetFontSize(24);
	strWidth = GetDrawStringWidth("Press Enter to Title", -1) / 2;
	DrawString(WINDOW_W / 2 - strWidth, 400, "Press Enter to Title", GetColor(255, 255, 255));
}