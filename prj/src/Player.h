#pragma once
#include "CharaBase.h"

class Player final : public CharaBase
{
	int invTime = 0;		// 無敵時間
	bool isHave = false;	// 持っているか

public:

	int score = 0;		// スコア

	Player()
	{
		pos.Set(400.0f, 300.0f);
		velocity.Set(0.0f, 0.0f);
		radius = 32;
	}
	~Player() override {

	}

	// 攻撃を食らう
	void HitDamage();

	// 無敵時間の間点滅
	void InvRender();

	// 宝箱の持つ位置を返す
	Var2<float> GetHavePos();

	// 動き
	void Move() override;
	// 描画
	void Render() override;
};