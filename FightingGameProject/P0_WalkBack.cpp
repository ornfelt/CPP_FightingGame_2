#include "P0_WalkBack.h"

namespace RB::PlayerStates::Aku
{
	void P0_WalkBack::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::NONE;

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(false));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::PlayerStates::Aku::P0_JumpUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingBack(new RB::PlayerStates::Aku::P0_Idle(), new RB::PlayerStates::Aku::P0_WalkBack()));

		EnterStateComponents();
	}

	void P0_WalkBack::OnExit()
	{
		ExitStateComponents();
	}

	void P0_WalkBack::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_WalkBack::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}