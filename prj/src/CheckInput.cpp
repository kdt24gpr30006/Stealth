#include "CheckInput.h"

void CheckInputKey::Update()
{
	// 全てのキーの入力状態を得る
	GetHitKeyStateAll(keyBuffer);
	for (int i = 0; i < KEY_NUM; i++)
	{
		if (keyBuffer[i] != 0)
		{
			// コードに対応するキーが押されていたら増やす
			keyPushFream[i]++;
		}
		else
		{
			if (keyPushFream[i] > 0)
			{
				// 離された瞬間だけ-1にする
				keyPushFream[i] = -1;
			}
			else
			{
				// 押されていなければ0にする
				keyPushFream[i] = 0;
			}
		}
	}

	// 左クリックの入力状態を得る
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		mouseLeftFream++;
	}
	else
	{
		mouseLeftFream = 0;
	}

	// 右クリックの入力状態を得る
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
