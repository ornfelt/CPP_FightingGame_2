#pragma once

#include "olcPixelGameEngine.h"

#include "Vector2.h"
#include "SpriteContainer.h"
#include "PlayerState.h"
#include "Loaded_HB_Data.h"

#include "HBox/AABB_Set.h"
#include "HBox/HBoxType.h"
#include "HBox/iAttackBoxDataController.h"

#include "iPlayer.h"
#include "iPlayerController.h"
#include "iPlayerAnimationController.h"
#include "iTargetBoxDataController.h"

namespace RB::Render
{
	class PlayerHBoxRenderer
	{
	public:
		PlayerHBoxRenderer() = default;
		~PlayerHBoxRenderer() = default;

	public:
		void Init(RB::Sprites::SpriteContainer* spriteContainer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderHBox(RB::Players::PlayerID playerID, RB::HBox::HBoxType boxType);

	private:
		void _Render(RB::Players::iPlayer* player, RB::HBox::AABB_Set* AABBs, olc::Pixel color);

		RB::Sprites::SpriteContainer* _spriteContainer = nullptr;
	};
}
