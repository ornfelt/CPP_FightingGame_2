#include "P0_Hadouken.h"

namespace RB::PlayerStates
{
	void P0_Hadouken::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_hadouken;

		AddStateComponent(new RB::PlayerStateComponents::FixSpecialMoveStatusDuringState(true));
		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight(GetPlayer()->OtherPlayerIsOnRightSide()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::PlayerStates::P0_Idle()));

		EnterStateComponents();
	}

	void P0_Hadouken::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Hadouken::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Hadouken::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}