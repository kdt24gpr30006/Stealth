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
	// �C���X�^���X�쐬
	player = std::make_shared<Player>();
	
	// csv�t�@�C������G�̏�����
	//enemy.emplace_back(std::make_shared<Enemy>();
	
	enemy.emplace_back(std::make_shared<Enemy>(Vec2<float>(static_cast<float>(WINDOW_W / 2 - 100), 200.0f), 0.0f, 50.0f, 100.0f, 4.0f));


	// �G�̎��E�摜�ǂݍ���
	enemySearchImage = LoadGraph("data/enemy/search.png");
}

void GameScene::Update()
{
	// ���݂̎����擾
	auto now = Clock::now();
	// �O�t���[���Ƃ̎��ԍ����v�Z
	std::chrono::duration<float> diff = now - prevTime;
	// �O�t���[������̌o�ߎ��Ԏ擾
	deltaTime = diff.count();
	// �O�t���[���̎����X�V
	prevTime = now;
	// ���o�ߎ��ԍX�V
	totalTime += deltaTime;

	// �X�V����
	player->Update((float)deltaTime);
	for (auto& e : enemy)
	{
		e->Update(totalTime);

		// �v���C���[�������Ă��邩
		if(e->CanSeePlayer(player))
		{
			// �����Ă�����R���\�[���ɕ\��
			printfDx("Player Spotted!\n");
		}
	}
}

void GameScene::Render()
{
	// �`�揈��
	player->Render();
	for (auto& e : enemy)
	{
		e->Draw(&enemySearchImage);
	}
}
