#include "P0_WalkBack.h"

namespace RB::PlayerStates::Aku
{
	void P0_WalkBack::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::NONE;

		RB::Players::Specs::MoveSpecs m = RB::Players::Specs::iSpecsController::Get()->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::PlayerStates::Aku::P0_JumpUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingBack(m.mWalk_Back_Speed, new RB::PlayerStates::Aku::P0_Idle(), new RB::PlayerStates::Aku::P0_WalkForward()));

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
