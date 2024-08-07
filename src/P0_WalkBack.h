#pragma once

#include "PlayerState.h"
#include "DoNotFixDirectionDuringState.h"
#include "TransitionToJumpUp.h"
#include "WhileMovingBack.h"

#include "iSpecsController.h"

#include "P0_JumpUp_0.h"
#include "P0_Idle.h"
#include "P0_WalkForward.h"

namespace RB::PlayerStates::Aku
{
	class P0_WalkBack : public RB::PlayerStates::PlayerState
	{
	public:
		P0_WalkBack() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
