#pragma once
#include "Var2.h"

class EntityBase
{
protected:
	Var2<float> pos;		// 座標
	Var2<float> velocity;	// 速度
	int radius;				// 半径
	int imageHandle;		// 画像ハンドル

public:

	EntityBase() : radius(0), imageHandle(-1) {}
	virtual ~EntityBase() {};

	// 更新
	virtual void Update() = 0;
	// 描画
	virtual void Render() = 0;
};