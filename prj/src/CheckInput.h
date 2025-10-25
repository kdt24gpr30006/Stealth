#pragma once

#include "dxlib.h"

class CheckInputKey
{
#define KEY_NUM 256

	// �L�[�̓��͏��
	char keyBuffer[KEY_NUM];

	// �L�[�̉�����Ă��鎞��
	int keyPushFream[KEY_NUM];

	// ���N���b�N����Ă��鎞��
	int mouseLeftFream = 0;
	
	// �E�N���b�N����Ă��鎞��
	int mouseRightFream = 0;	

	// �R���X�g���N�^�[
	CheckInputKey()
	{
		for (int i = 0; i < KEY_NUM; ++i)
		{
			keyBuffer[i] = 0;
			keyPushFream[i] = 0;
		}
	}

public:

	// �R�s�[����֎~
	CheckInputKey(const CheckInputKey&) = delete;
	CheckInputKey& operator=(const CheckInputKey&) = delete;
	// �C���X�^���X��Ԃ�
	static CheckInputKey& GetInstance()
	{
		static CheckInputKey instance;
		return instance;
	}
	// �f�X�g���N�^�[
	~CheckInputKey() {}

	// ���͏�Ԃ��X�V
	void Update();


	// �L�[�{�[�h

	// �����ꂽ�u�Ԃ��擾
	bool PushHitKey(int key) const;

	// �������u�Ԃ��擾
	bool ReleaseHitKey(int key) const;


	// �}�E�X
	// �w�肳��Ȃ���΂ǂ����̃N���b�N�ł�����

	// �����ꂽ�u�Ԃ��擾
	bool PushMouseInput(int button = MOUSE_INPUT_LEFT | MOUSE_INPUT_RIGHT) const;

	// �������u�Ԃ��擾
	bool ReleaseMouseInput(int button = MOUSE_INPUT_LEFT | MOUSE_INPUT_RIGHT) const;
};