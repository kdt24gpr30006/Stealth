#include "GameScene.h"
#include "DxLib.h"
#include "WinMain.h"

void GameScene::Init()
{
	// インスタンス作成
	player = std::make_shared<Player>();
	enemy.emplace_back(std::make_shared<Enemy>(Vec2<float>(static_cast<float>(WINDOW_W / 2 - 100), 200.0f), 0.0f, 50.0f, 100.0f, 4.0f));
	enemy.emplace_back(std::make_shared<Enemy>(Vec2<float>(static_cast<float>(WINDOW_W / 2 + 100), 400.0f), 90.0f, 30.0f, 100.0f, 4.0f));
}

void GameScene::Update()
{
	// 現在の時刻取得
	auto now = Clock::now();
	// 前フレームとの時間差分計算
	std::chrono::duration<float> diff = now - prevTime;
	// 前フレームからの経過時間取得
	deltaTime = diff.count();
	// 前フレームの時刻更新
	prevTime = now;
	// 総経過時間更新
	totalTime += deltaTime;

	// 更新処理
	player->Update((float)deltaTime);
	for (auto& e : enemy)
	{
		e->Update(totalTime);
	}
}

void GameScene::Render()
{
	// 描画処理
	player->Render();
	for (auto& e : enemy)
	{
		// プレイヤーが見えているか
		bool detected = e->CanSeePlayer(player);
		e->Draw(detected);
	}
}
