#pragma once
#include "SpriteRenderer.h"
#include "AABB.h"

#include "ActivePlayerStates.h"
#include "HBoxType.h"

#include "iHurtBoxDataController.h"
#include "iPlayerAnimationController.h"
#include "iPlayerController.h"

namespace RB::Render
{
	class PlayerHBoxRenderer
	{
	public:
		PlayerHBoxRenderer() = default;
		~PlayerHBoxRenderer() = default;

	public:
		void Init(SpriteRenderer* spriteRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderHBox(RB::Players::PlayerID playerID, RB::HBox::HBoxType boxType);

	private:
		void _Render(RB::Players::iPlayer* player, RB::HBox::HBoxData* data, olc::Pixel color);

		SpriteRenderer* _spriteRenderer = nullptr;
	};
}