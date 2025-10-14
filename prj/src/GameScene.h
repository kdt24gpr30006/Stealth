#pragma once
#include <memory>
#include <vector>
#include "Player.h"
#include "Enemy.h"


class GameScene final
{
	// �v���C���[
	std::unique_ptr<Player> player;
	// �G�l�~�[
	std::vector<std::unique_ptr<Enemy>> enemy;

	// �R���X�g���N�^
	GameScene() {}

public:

	// �R�s�[����֎~
	GameScene(const GameScene&) = delete;
	GameScene& operator=(const GameScene&) = delete;

	// �C���X�^���X��Ԃ�
	static GameScene& GetInstance()
	{
		static GameScene instance;
		return instance;
	}

	// ����������
	void Init();
	// �X�V����
	void Update();
	// �`�揈��
	void Render();
};