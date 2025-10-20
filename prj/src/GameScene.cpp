#include "GameScene.h"
#include "DxLib.h"
#include "WinMain.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void GameScene::LoadEnemies()
{
	std::ifstream file("data/enemy/csv/Init.csv");
}

void GameScene::Init()
{
	// インスタンス作成
	player = std::make_shared<Player>();
	
	// csvファイルから敵の初期化
	//enemy.emplace_back(std::make_shared<Enemy>();
	
	enemy.emplace_back(std::make_shared<Enemy>(Vec2<float>(static_cast<float>(WINDOW_W / 2 - 100), 200.0f), 0.0f, 50.0f, 100.0f, 4.0f));


	// 敵の視界画像読み込み
	enemySearchImage = LoadGraph("data/enemy/search.png");
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

		// プレイヤーが見えているか
		if(e->CanSeePlayer(player))
		{
			// 見えていたらコンソールに表示
			printfDx("Player Spotted!\n");
		}
	}
}

void GameScene::Render()
{
	// 描画処理
	player->Render();
	for (auto& e : enemy)
	{
		e->Draw(&enemySearchImage);
	}
}
