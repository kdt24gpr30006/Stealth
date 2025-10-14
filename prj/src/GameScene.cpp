#include "GameScene.h"

void GameScene::Init()
{
	player = std::make_unique<Player>();
	enemy.push_back(std::make_unique<Enemy>());
}

void GameScene::Update()
{
	player->Update();
	for(auto& e : enemy)
	{
		e->Update();
	}
}

void GameScene::Render()
{
	player->Render();
}
