#pragma once

#include "PlayerState.h"
#include "DoNotFixDirectionDuringState.h"
#include "TransitionToJumpForward.h"
#include "TransitionToJumpUp.h"
#include "WhileMovingForward.h"

#include "iSpecsController.h"

#include "P0_JumpForwardUp_0.h"
#include "P0_JumpUp_0.h"
#include "P0_Idle.h"
#include "P0_WalkBack.h"

namespace RB::PlayerStates::Aku
{
	class P0_WalkForward : public RB::PlayerStates::PlayerState
	{
	public:
		P0_WalkForward() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
