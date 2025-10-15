#pragma once
#include <vector>
#include <memory>
#include "Var2.h"
#include "Image.h"

class EntityBase
{
protected:
	Var2<float> pos;							// 座標
	Var2<float> velocity;						// 速度
	float radius;								// 半径
	std::vector<std::unique_ptr<Image>> image;	// 画像

public:

	EntityBase() : radius(0){}
	virtual ~EntityBase() {};

	// 更新
	virtual void Update() = 0;
	// 描画
	virtual void Render() = 0;
};