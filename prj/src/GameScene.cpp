#include "GameScene.h"
#include "DxLib.h"
#include "WinMain.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::vector<std::shared_ptr<Enemy>> GameScene::LoadEnemyInfo()
{
	// ファイル読み込み
	std::ifstream file("data/enemy/csv/EnemyInit.csv");

    // 読み込めたか
    if (!file.is_open()) {
        std::runtime_error error("ファイルの読み込みに失敗");
        throw error;
    }

    std::string line;
    // 一行目スキップ
    std::getline(file, line);

    // 返す敵のベクター
    std::vector<std::shared_ptr<Enemy>> retEnemies;

    // 各行を読み込み、敵キャラクターを作成
    while (std::getline(file, line))
    {
        std::stringstream lineStream(line);
        std::string cell;

        float x, y, r, angle, fov, dist, speed;

        // CSVの各カラムを読み込む
        // X座標
        std::getline(lineStream, cell, ',');
        x = std::stof(cell);

        // Y座標
        std::getline(lineStream, cell, ',');
        y = std::stof(cell);

        std::getline(lineStream, cell, ',');
        r = std::stof(cell);

        // 角度
        std::getline(lineStream, cell, ',');
        angle = std::stof(cell);

        // 視野角
        std::getline(lineStream, cell, ',');
        fov = std::stof(cell);

        // 認識範囲
        std::getline(lineStream, cell, ',');
        dist = std::stof(cell);

        // 移動速度
        std::getline(lineStream, cell, ',');
        speed = std::stof(cell);

        // 敵キャラクターを作成
        auto enemy = std::make_shared<Enemy>(Vec2<float>(x, y), r, angle, fov, dist, speed);

        // 巡回経路の設定
        while (std::getline(lineStream, cell, ','))
        {
            if (cell.empty() == false) 
            {
                float patrolX = std::stof(cell);
                std::getline(lineStream, cell, ',');
                float patrolY = std::stof(cell);
                enemy->SetPatrolRoute(Vec2<float>(patrolX, patrolY));
            }
        }

        // 敵キャラクターをベクターに追加
        retEnemies.emplace_back(enemy);
    }

    file.close();

	return retEnemies;
}

void GameScene::Init()
{
	// インスタンス作成
	player = std::make_shared<Player>();
    element = std::make_shared<Element>();
	
    // インスタンス初期化
    player->Init();
    element->Init();

	// csvファイルから敵の初期化
	enemies = LoadEnemyInfo();

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
	player->Update(deltaTime);
	for (auto& enemy : enemies)
	{
		enemy->Update(deltaTime);

		// プレイヤーが見えているか
		if(enemy->CanSeePlayer(player))
		{
			// 見えていたらコンソールに表示
			printfDx("Player Spotted!\n");
		}
	}
    element->Update();
}

void GameScene::Render()
{
	// 描画処理
	player->Render();
	for (auto& enemy : enemies)
	{
		enemy->Render(&enemySearchImage);
	}
    element->Render();
}
