#pragma once

#include <ctime>		// �W��C ���C�u���� �w�b�_�[ <time.h> ���C���N���[�h���A�֘A���閼�O�� std ���O��Ԃɒǉ����܂��B
#include "DxLib.h"		// DxLib
#include "CheckInput.h"
#include "WinMain.h"

// �Q�[���֌W
class Game
{
	// ���͏����֐�
	void input();

	// ��ʍX�V�֐�
	void render();

	// �����Đ������֐�
	void sound();

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

	virtual ~Game()
	{

	}
};