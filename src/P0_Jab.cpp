#include "P0_Jab.h"

namespace RB::PlayerStates::Aku
{
	void P0_Jab::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_jab;

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::DetectHit());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::PlayerStates::Aku::P0_Idle()));

		EnterStateComponents();
	}

	void P0_Jab::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Jab::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Jab::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
