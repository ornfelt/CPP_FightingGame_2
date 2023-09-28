#pragma once
#include "ControllerBase.h"
#include "HBoxDataList.h"

namespace RB::HBox
{
	class iHitBoxDataController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual HBoxDataList* GetDataList(RB::Sprites::SpriteEnum spriteEnum) = 0;
		virtual const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const = 0;
	};

	extern iHitBoxDataController* HITBOX_DATA_CONTROLLER;
}