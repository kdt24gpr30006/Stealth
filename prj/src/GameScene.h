#pragma once
#include "Player.h"
#include "Enemy.h"
#include <chrono>
#include <vector>
#include <memory>

class GameScene
{
	// プレイヤー
	std::shared_ptr<Player> player;
	// 敵キャラクター
	std::vector<std::shared_ptr<Enemy>> enemy;

	// 時間計測用クロック
	using Clock = std::chrono::steady_clock;
	// 前フレームの時刻
	Clock::time_point prevTime;
	// 前フレームからの経過時間
	float deltaTime;
	// 総経過時間
	float  totalTime;

	// コンストラクタ
	GameScene() :prevTime(Clock::now()), deltaTime(0.0f), totalTime(0.0f) {}
	~GameScene() {}

public:

	// コピー禁止
	GameScene(const GameScene&) = delete;
	GameScene& operator=(const GameScene&) = delete;

	// シングルトンインスタンス取得
	static GameScene& GetInstance()
	{
		static GameScene instance;
		return instance;
	}

	// 初期化
	void Init();
	// 更新
	void Update();
	// 描画
	void Render();
};
