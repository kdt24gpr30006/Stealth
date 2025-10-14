#include "CheckInput.h"

void CheckInputKey::Update()
{
	// �S�ẴL�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(keyBuffer);
	for (int i = 0; i < KEY_NUM; i++)
	{
		if (keyBuffer[i] != 0)
		{
			// �R�[�h�ɑΉ�����L�[��������Ă����瑝�₷
			keyPushFream[i]++;
		}
		else
		{
			if (keyPushFream[i] > 0)
			{
				// �����ꂽ�u�Ԃ���-1�ɂ���
				keyPushFream[i] = -1;
			}
			else
			{
				// ������Ă��Ȃ����0�ɂ���
				keyPushFream[i] = 0;
			}
		}
	}

	// ���N���b�N�̓��͏�Ԃ𓾂�
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		mouseLeftFream++;
	}
	else
	{
		mouseLeftFream = 0;
	}

	// �E�N���b�N�̓��͏�Ԃ𓾂�
	if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		mouseRightFream++;
	}
	else
	{
		mouseRightFream = 0;
	}
}

bool CheckInputKey::PushHitKey(int key)
{
	if (keyPushFream[key] == 1)
	{
		return true;
	}
	return false;
}

bool CheckInputKey::ReleaseHitKey(int key)
{
	if (keyPushFream[key] == -1)
	{
		return true;
	}
	return false;
}

bool CheckInputKey::PushMouseInput(int button)
{
	if (button & MOUSE_INPUT_LEFT)
	{
		if (mouseLeftFream == 1)
		{
			return true;
		}
	}
	if (button & MOUSE_INPUT_RIGHT)
	{
		if (mouseRightFream == 1)
		{
			return true;
		}
	}
	return false;
}

bool CheckInputKey::ReleaseMouseInput(int button)
{
	if (button & MOUSE_INPUT_LEFT)
	{
		if (mouseLeftFream == -1)
		{
			return true;
		}
	}
	if (button & MOUSE_INPUT_RIGHT)
	{
		if (mouseRightFream == -1)
		{
			return true;
		}
	}
	return false;
}
