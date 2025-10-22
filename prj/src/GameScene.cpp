#include "GameScene.h"
#include "DxLib.h"
#include "WinMain.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::vector<std::shared_ptr<Enemy>> GameScene::LoadEnemyInfo()
{
	// �t�@�C���ǂݍ���
	std::ifstream file("data/enemy/csv/Init.csv");

    // �ǂݍ��߂���
    if (!file.is_open()) {
        std::runtime_error error("�t�@�C���̓ǂݍ��݂Ɏ��s");
        throw error;
    }

    std::string line;
    // ��s�ڃX�L�b�v
    std::getline(file, line);

    std::vector<std::shared_ptr<Enemy>> enemies;

    // �e�s��ǂݍ��݁A�G�L�����N�^�[���쐬
    while (std::getline(file, line))
    {
        std::stringstream lineStream(line);
        std::string cell;

        float x, y, angle, fov, speed;
        double dist;

        // CSV�̊e�J������ǂݍ���
        // X���W
        std::getline(lineStream, cell, ',');
        x = std::stof(cell);

        // Y���W
        std::getline(lineStream, cell, ',');
        y = std::stof(cell);

        // �p�x
        std::getline(lineStream, cell, ',');
        angle = std::stof(cell);

        // ����p
        std::getline(lineStream, cell, ',');
        fov = std::stof(cell);

        // �F���͈�
        std::getline(lineStream, cell, ',');
        dist = std::stof(cell);

        // �ړ����x
        std::getline(lineStream, cell, ',');
        speed = std::stof(cell);

        // �G�L�����N�^�[���쐬
        auto enemy = std::make_shared<Enemy>(Vec2<float>(x, y), angle, fov, dist, speed);

        // ����o�H�̐ݒ�
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

        // �G�L�����N�^�[���x�N�^�[�ɒǉ�
        enemies.emplace_back(enemy);
    }

    file.close();
    return enemies;
}

void GameScene::Init()
{
	// �C���X�^���X�쐬
	player = std::make_shared<Player>();
	
	// csv�t�@�C������G�̏�����
	enemies = LoadEnemyInfo();

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
	for (auto& enemy : enemies)
	{
		enemy->Update(totalTime);

		// �v���C���[�������Ă��邩
		if(enemy->CanSeePlayer(player))
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
	for (auto& enemy : enemies)
	{
		enemy->Draw(&enemySearchImage);
	}
}
