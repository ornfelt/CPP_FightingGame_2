#include "TriggerJumpUp.h"

namespace RB::PlayerStateComponents
{
	void TriggerJumpUp::OnEnter()
	{

	}

	void TriggerJumpUp::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Input::INPUT_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::PlayerID playerID = player->GetPlayerID();

		RB::Input::iInputObj* jumpPress = RB::Input::INPUT_CONTROLLER->GetUnusedInputObj_FIFO(playerID, RB::Input::PlayerInput::JUMP);
		olc::HWButton forwardHold;

		if (player->OtherPlayerIsOnRightSide())
		{
			forwardHold = RB::Input::INPUT_CONTROLLER->GetKeyBinding(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);
		}
		else
		{
			forwardHold = RB::Input::INPUT_CONTROLLER->GetKeyBinding(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		}
		
		if (jumpPress != nullptr && forwardHold.bHeld == false)
		{
			jumpPress->SetUsedStatus(true);

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_JumpUp());
		
			return;
		}
	}
}