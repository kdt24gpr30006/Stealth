#include "GameScene.h"
#include "Squid.h"
#include "Shark.h"


void GameScene::Init()
{
	player = std::make_unique<Player>();
	// sharkインスタンス
	enemy.push_back(std::make_unique<Shark>());
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
