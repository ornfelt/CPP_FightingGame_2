#include "BackgroundObj.h"

namespace RB::Background
{
	BackgroundObj::BackgroundObj(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d pos, float_t percentage)
	{
		_spriteEnum = spriteEnum;
		_position = pos;
		_percentage = percentage;
	}

	void BackgroundObj::Init()
	{

	}

	void BackgroundObj::OnUpdate()
	{

	}

	void BackgroundObj::OnFixedUpdate()
	{

	}
}