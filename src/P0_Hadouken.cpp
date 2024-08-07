#include "P0_Hadouken.h"

namespace RB::PlayerStates::Aku
{
	void P0_Hadouken::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_hadouken;

		AddStateComponent(new RB::PlayerStateComponents::FixSpecialMoveStatusDuringState(true));
		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::PlayerStates::Aku::P0_Idle()));

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
