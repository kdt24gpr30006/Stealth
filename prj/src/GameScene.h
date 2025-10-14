#pragma once
#include <memory>
#include <vector>
#include "Player.h"
#include "Enemy.h"


class GameScene final
{
	// プレイヤー
	std::unique_ptr<Player> player;
	// エネミー
	std::vector<std::unique_ptr<Enemy>> enemy;

	// コンストラクタ
	GameScene() {}

public:

	// コピー代入禁止
	GameScene(const GameScene&) = delete;
	GameScene& operator=(const GameScene&) = delete;

	// インスタンスを返す
	static GameScene& GetInstance()
	{
		static GameScene instance;
		return instance;
	}

	// 初期化処理
	void Init();
	// 更新処理
	void Update();
	// 描画処理
	void Render();
};