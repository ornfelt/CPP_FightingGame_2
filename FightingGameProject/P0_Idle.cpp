#include "P0_Idle.h"

namespace RB::P0_States
{
	void P0_Idle::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;

		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveForward());
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveBack());

		EnterStateComponents();
	}

	void P0_Idle::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Idle::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}