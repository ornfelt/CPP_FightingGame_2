#include "TransitionToWalkForward.h"

namespace RB::PlayerStateComponents
{
	void TransitionToWalkForward::OnEnter()
	{
		_moveForwardOnPress.SetStateMachineID(_state->GetStateMachineID());
	}

	void TransitionToWalkForward::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player == nullptr)
		{
			return;
		}

		_moveForwardOnPress.OnUpdate();

		if (_moveForwardOnPress.ProcMoveForward())
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();

			stateMachine->QueueNextState(new RB::PlayerStates::P0_MoveForward());
		}
	}
}