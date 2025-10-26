#include "GameScene.h"
#include "DxLib.h"
#include "WinMain.h"
#include "CollisionUtils.h"
#include "GameOver.h"
#include "GameClear.h"
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

		float x, y, radius, angle, fov, dist, speed;

		// CSVの各カラムを読み込む
		// X座標
		std::getline(lineStream, cell, ',');
		x = std::stof(cell);

		// Y座標
		std::getline(lineStream, cell, ',');
		y = std::stof(cell);

		std::getline(lineStream, cell, ',');
		radius = std::stof(cell);

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
		auto enemy = std::make_shared<Enemy>(Vec2<float>(x, y), radius, angle, fov, dist, speed);

		// 巡回経路の設定
		while (std::getline(lineStream, cell, ','))
		{
			// セルが空じゃないなら読み込み処理
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

bool GameScene::CheckLineWithLine(const Vec2<float>& lineA1, const Vec2<float>& lineA2, const Vec2<float>& lineB1, const Vec2<float>& lineB2)
{
	// １つめの線の向き
	Vec2<float> dirA = lineA2 - lineA1;
	// 2つめの線の向き
	Vec2<float> dirB = lineB2 - lineB1;
	// 2の線の始点の差
	Vec2<float> startDiff = lineA1 - lineB1;

	// 外積を計算(ベクトルの向きの計算)
	float crossAB = dirA.x * dirB.y - dirA.y * dirB.x;

	// この値が0なら平行だから交わってない
	if (crossAB == 0.0f)
	{
		return false;
	}

	// その位置で交わるか
	float invCross = 1.0f / crossAB;

	// 線Aと線Bの交差位置
	float ratioA = (dirB.x * startDiff.y - dirB.y * startDiff.x) * invCross;
	float ratioB = (dirA.x * startDiff.y - dirA.y * startDiff.x) * invCross;

	// 交差判定
	if (ratioA >= 0.0f && ratioA <= 1.0f && ratioB >= 0.0f && ratioB <= 1.0f)
	{
		return true;
	}
	return false;

}

bool GameScene::CheckLineWall(const Vec2<float>& from, const Vec2<float>& to, const std::vector<std::shared_ptr<Wall>>& walls)
{
	// 壁の数だけループして
	for (const auto& wall : walls)
	{
		// 一つでも交差していたら即return
		// 矩形の4辺を線分として判定
		if (CheckLineWithLine(from, to, wall->leftUp, wall->rightUp)) return true;
		if (CheckLineWithLine(from, to, wall->rightUp, wall->rightDown)) return true;
		if (CheckLineWithLine(from, to, wall->rightDown, wall->leftDown)) return true;
		if (CheckLineWithLine(from, to, wall->leftDown, wall->leftUp)) return true;
	}

	return false;
}

bool GameScene::CheckPlayerGoal(const Vec2<float>& playerPos, const float playerRadius, const Vec2<float>& goalPos, const float goalRadius)
{
	// プレイヤーとゴールの距離を取得
	auto distSq = (playerPos - goalPos).GetLengthSq();
	// 半径の和を取得
	float radiusSum = playerRadius + goalRadius;
	// 衝突判定
	if (distSq <= radiusSum * radiusSum)
	{
		return true;
	}
	return false;
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
	// プレイヤー
	player->Update(deltaTime);

	// プレイヤーと壁の衝突判定
	for (const auto& wall : element->GetWalls())
	{
		Vec2<float> pushVec(0.0f, 0.0f);
		CheckCircleWithWall(player->GetPos(), player->GetRadius(), *wall, pushVec);
		// 衝突していたら押し戻す
		player->SetPos(player->GetPos() + pushVec);
	}

	// プレイヤーがゴールしたか
	if (CheckPlayerGoal(player->GetPos(), player->GetRadius(), element->GetGoalPos(), element->GetGoalRadius()))
	{
		// ゲームクリアへ移行
		manager->ChengeScene(std::make_shared<GameClearScene>(manager));
	}

	// 敵
	for (auto& enemy : enemies)
	{
		enemy->Update(deltaTime);

		// プレイヤーが見える範囲にいるか
		bool canSee = enemy->CanSeePlayer(player);

		// 視界が遮られていないか
		bool block = false;

		// 見えているなら
		if (canSee)
		{
			block = CheckLineWall(enemy->GetPos(), player->GetPos(), element->GetWalls());
		}

		// 完全に見えている
		if (canSee && block == false)
		{
			// ゲームオーバーへ移行
			manager->ChengeScene(std::make_shared<GameOverScene>(manager));
		}
	}
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
