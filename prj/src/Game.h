#pragma once

#include <ctime>		// �W��C ���C�u���� �w�b�_�[ <time.h> ���C���N���[�h���A�֘A���閼�O�� std ���O��Ԃɒǉ����܂��B
#include "DxLib.h"		// DxLib
#include "CheckInput.h"
#include "WinMain.h"
#include "GameScene.h"

// �Q�[���֌W
class Game
{
	// �Q�[���V�[��
	GameScene& gameScene = GameScene::GetInstance();
	// �C���v�b�g
	CheckInputKey& inputKey = CheckInputKey::GetInstance();

	// ���͏����֐�
	void input();

	// ��ʍX�V�֐�
	void GameLoop();

	Game() {}
public:

	// �R�s�[����֎~
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	// �C���X�^���X��Ԃ�
	static Game& GetInstance()
	{
		static Game instance;
		return instance;
	}

	// �������֐�
	bool Init();

	// �X�V�֐�
	void Loop();

	// �I���֐�
	void End();
};