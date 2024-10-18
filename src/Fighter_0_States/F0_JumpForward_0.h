#pragma once

#include "../Players/PlayerState.h"
#include "../PlayerStateComponents/MarkInitiallyFacingRight.h"
#include "../PlayerStateComponents/MoveUpOnJump.h"
#include "../PlayerStateComponents/MoveForwardOnJump_0.h"

#include "../Players/iSpecsController.h"

#include "../Fighter_0_States/F0_JumpForward_1.h"

namespace RB::Fighter_0_States
{
	class F0_JumpForward_0 : public RB::Players::PlayerState
	{
	public:
		F0_JumpForward_0() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}