#pragma once
#include "CharaBase.h"
#include <string>


enum PlayerState
{
	IDLE,
	MOVE,
	CARRY,
	MAX,
};

class Player final : public CharaBase
{
	int invTime = 0;			// 無敵時間
	bool isHave = false;		// 持っているか
	PlayerState state = MOVE;	// 状態
	int imageAngle = 0;			// 画像の角度

	// 無敵かどうか
	bool IsInv();

	// 無敵時間の間点滅
	void InvRender();

	// 動き
	void Move();

	// 画像角度の更新
	void UpdateAngle();

public:

	int score = 0;		// スコア

	Player();
	~Player() override {

	}

	// 攻撃を食らう
	void HitDamage();

	// 宝箱を拾う
	void PickUp();

	// 宝箱の持つ位置を返す
	Var2<float> GetHavePos();

	// 更新
	void Update() override;

	// 描画
	void Render() override;
};