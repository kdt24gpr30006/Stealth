#pragma once

#include "SceneManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Element.h"
#include <chrono>
#include <vector>
#include <memory>

class GameScene : public Scene
{
	// プレイヤー
	std::shared_ptr<Player> player;
	// 敵キャラクター
	std::vector<std::shared_ptr<Enemy>> enemies;
	// ゲームの要素
	std::shared_ptr<Element> element;

	// 敵の視界画像
	int enemySearchImage;

	// 時間計測用クロック
	using Clock = std::chrono::steady_clock;
	// 前フレームの時刻
	Clock::time_point prevTime;
	// 前フレームからの経過時間
	float deltaTime;
	// 総経過時間
	float  totalTime;

	// 敵の情報をcsvから読み込み
	std::vector<std::shared_ptr<Enemy>> LoadEnemyInfo();

	// 線分と線分の交差判定
	bool CheckLineWithLine(const Vec2<float>& lineA1, const Vec2<float>& lineA2, const Vec2<float>& lineB1, const Vec2<float>& lineB2);
	// プレイヤーと敵の間に壁があるか
	bool CheckLineWall(const Vec2<float>& from, const Vec2<float>& to, const std::vector<std::shared_ptr<Wall>>& walls);

	// プレイヤーがゴールしたか
	bool CheckPlayerGoal(const Vec2<float>& playerPos, const float playerRadius, const Vec2<float>& goalPos, const float goalRadius);

public:

	// コンストラクタ
	GameScene(std::shared_ptr<SceneManager> pManager) : Scene(pManager), prevTime(Clock::now()), deltaTime(0.0f), totalTime(0.0f), enemySearchImage(-1) {}

	~GameScene()
	{
		// 画像の解放
		if (enemySearchImage != -1)
		{
			DeleteGraph(enemySearchImage);
			enemySearchImage = -1;
		}
	}

	// 初期化
	void Init();
	// 更新
	void Update();
	// 描画
	void Render();
};
