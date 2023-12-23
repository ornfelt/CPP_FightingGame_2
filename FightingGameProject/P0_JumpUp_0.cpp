#include "P0_JumpUp_0.h"

namespace RB::PlayerStates::Aku
{
	void P0_JumpUp_0::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::aku_jump_up_0;

		RB::Players::Specs::MoveSpecs moveSpecs = RB::Players::Specs::iSpecsController::instance->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(moveSpecs.mJumpUp_totalFrames, moveSpecs.mJumpUp_speedMultiplier, new P0_JumpUp_1()));

		EnterStateComponents();
	}

	void P0_JumpUp_0::OnExit()
	{
		ExitStateComponents();
	}

	void P0_JumpUp_0::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpUp_0::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}