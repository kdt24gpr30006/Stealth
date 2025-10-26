#include "WinMain.h"
#include "TitleScene.h"
#include "GameScene.h"
#include <DxLib.h>

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	// エンターキーが押されたらゲームシーンへ移行
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		manager->ChengeScene(std::make_shared<GameScene>(manager));
	}
}

void TitleScene::Render()
{
	SetFontSize(48);
	int strWidth = GetDrawStringWidth("Shadow Heist", -1) / 2;
	DrawString(WINDOW_W / 2 - strWidth, 200, "Shadow Heist", GetColor(0, 0, 255));
	SetFontSize(24);
	strWidth = GetDrawStringWidth("Press Enter to Start", -1) / 2;
	DrawString(WINDOW_W / 2 - strWidth, 400, "Press Enter to Start", GetColor(255, 255, 255));
}
