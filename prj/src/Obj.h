#pragma once
#include "EntityBase.h"

class Obj : public EntityBase
{
	bool isHave = false;	// ‚½‚ê‚Ä‚¢‚é‚©
	bool isGoal = false;	// ƒS[ƒ‹‚µ‚Ä‚¢‚é‚©

public:

	Obj(){}
	virtual ~Obj() = 0;

	// “®‚«
	virtual void Move() = 0;
	// •`‰æ
	virtual void Render() = 0;
};