#pragma once

#include "PlayerState.h"
#include "MoveUpOnJump.h"
#include "MarkInitiallyFacingRight.h"

#include "iSpecsController.h"

#include "P0_JumpUp_1.h"

namespace RB::PlayerStates::Aku
{
	class P0_JumpUp_0 : public RB::PlayerStates::PlayerState
	{
	public:
		P0_JumpUp_0() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
