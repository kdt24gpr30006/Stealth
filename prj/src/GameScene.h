#pragma once
#include "Player.h"
#include "Enemy.h"
#include <chrono>
#include <vector>
#include <memory>

class GameScene
{
	// �v���C���[
	std::shared_ptr<Player> player;
	// �G�L�����N�^�[
	std::vector<std::shared_ptr<Enemy>> enemies;

	// �G�̎��E�摜
	int enemySearchImage;	

	// ���Ԍv���p�N���b�N
	using Clock = std::chrono::steady_clock;
	// �O�t���[���̎���
	Clock::time_point prevTime;
	// �O�t���[������̌o�ߎ���
	float deltaTime;
	// ���o�ߎ���
	float  totalTime;

	// �G�̏���csv����ǂݍ���
	std::vector<std::shared_ptr<Enemy>> LoadEnemyInfo();

	// �R���X�g���N�^
	GameScene() :
		prevTime(Clock::now()), deltaTime(0.0f), totalTime(0.0f), enemySearchImage(-1){}
	~GameScene() 
	{
		// �摜�̉��
		if (enemySearchImage != -1)
		{
			DeleteGraph(enemySearchImage);
			enemySearchImage = -1;
		}
	}

public:

	// �R�s�[�֎~
	GameScene(const GameScene&) = delete;
	GameScene& operator=(const GameScene&) = delete;

	// �V���O���g���C���X�^���X�擾
	static GameScene& GetInstance()
	{
		static GameScene instance;
		return instance;
	}

	// ������
	void Init();
	// �X�V
	void Update();
	// �`��
	void Render();
};
