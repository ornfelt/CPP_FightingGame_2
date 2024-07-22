#pragma once

#include "ControllerT.h"

#include "Vector2.h"
#include "SpriteType.h"

#include "Render/iAnimationObj.h"

namespace RB::Render
{
	class iVFXAnimationController : public RB::Controllers::ControllerT<iVFXAnimationController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual iAnimationObj* InstantiateAnimation(RB::Sprites::SpriteType spriteType, RB::Vector2 pos) = 0;
	};
}
