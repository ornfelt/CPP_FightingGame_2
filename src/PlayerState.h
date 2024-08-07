#pragma once

#include <vector>
#include <iostream>

#include "StateBase.h"
#include "SpriteType.h"

#include "iPlayer.h"
#include "iPlayerController.h"
#include "iPlayerBoxDataController.h"
#include "iPlayerAnimationController.h"

namespace RB::PlayerStates
{
	class PlayerState : public RB::States::StateBase
	{
	public:
		static std::vector<PlayerState*> allPlayerStates;
		static PlayerState* GetPlayerState(RB::Players::PlayerID playerID);
		static void EraseAll();

	public:
		PlayerState();
		~PlayerState() override;

		void ErasePreviousStates() override;

	public:
		RB::Players::iPlayer* GetPlayer();
		RB::Sprites::SpriteType GetSpriteType();
		void AutoUpdatePlayerBox();

	protected:
		RB::Sprites::SpriteType _spriteType = RB::Sprites::SpriteType::NONE;
	};
}
