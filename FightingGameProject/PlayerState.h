#pragma once
#include <vector>

#include "StateBase.h"

#include "iPlayerController.h"
#include "iPlayer.h"

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

		void ClearRemainingStates() override;

	public:
		RB::Players::iPlayer* GetPlayer();
		RB::Sprites::SpriteEnum GetSpriteEnum();
		bool ContainsState(unsigned int stateID);

	protected:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
	};
}