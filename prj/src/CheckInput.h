#pragma once

#include "dxlib.h"

class CheckInputKey
{
#define KEY_NUM 256

	// キーの入力状態
	char keyBuffer[KEY_NUM];

	// キーの押されている時間
	int keyPushFream[KEY_NUM];

	// 左クリックされている時間
	int mouseLeftFream = 0;
	
	// 右クリックされている時間
	int mouseRightFream = 0;	

	// コンストラクター
	CheckInputKey()
	{
		for (int i = 0; i < KEY_NUM; ++i)
		{
			keyBuffer[i] = 0;
			keyPushFream[i] = 0;
		}
	}

public:

	// コピー代入禁止
	CheckInputKey(const CheckInputKey&) = delete;
	CheckInputKey& operator=(const CheckInputKey&) = delete;
	// インスタンスを返す
	static CheckInputKey& GetInstance()
	{
		static CheckInputKey instance;
		return instance;
	}
	// デストラクター
	~CheckInputKey() {}

	// 入力状態を更新
	void Update();


	// キーボード

	// 押された瞬間を取得
	bool PushHitKey(int key) const;

	// 離した瞬間を取得
	bool ReleaseHitKey(int key) const;


	// マウス
	// 指定されなければどっちのクリックでも反応

	// 押された瞬間を取得
	bool PushMouseInput(int button = MOUSE_INPUT_LEFT | MOUSE_INPUT_RIGHT) const;

	// 離した瞬間を取得
	bool ReleaseMouseInput(int button = MOUSE_INPUT_LEFT | MOUSE_INPUT_RIGHT) const;
};