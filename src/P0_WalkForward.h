#pragma once

#include "Players/PlayerState.h"
#include "PlayerStateComponents/DoNotFixDirectionDuringState.h"
#include "PlayerStateComponents/TransitionToJumpForward.h"
#include "PlayerStateComponents/TransitionToJumpUp.h"
#include "PlayerStateComponents/WhileMovingForward.h"

#include "Players/iSpecsController.h"

#include "Fighter_0_States/P0_JumpForwardUp_0.h"
#include "Fighter_0_States/P0_JumpUp_0.h"
#include "Fighter_0_States/P0_Idle.h"
#include "P0_WalkBack.h"

namespace RB::Fighter_0_States
{
	class P0_WalkForward : public RB::Players::PlayerState
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
