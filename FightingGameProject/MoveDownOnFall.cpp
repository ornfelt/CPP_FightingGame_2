#include "MoveDownOnFall.h"

namespace RB::PlayerStateComponents
{
	/// <summary>
	/// total frames to reach max fall speed
	/// </summary>
	MoveDownOnFall::MoveDownOnFall(size_t totalFrames, float_t multiplier)
	{
		_totalFrames = totalFrames;
		_multiplier = multiplier;
	}

	void MoveDownOnFall::OnEnter()
	{

	}

	void MoveDownOnFall::OnFixedUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		size_t frame = _state->GetCumulatedFixedUpdates();

		//get vertical down
		float_t percentage = (float_t)frame / (float_t)_totalFrames;

		if (percentage >= 1.0f)
		{
			percentage = 1.0f;
		}

		float_t amount = 1.0f - RB::EaseEquations::Ease::EaseOutSine(percentage);
		float_t result = amount * _multiplier;

		int32_t y = player->GetPosition().y;

		//transition to idle
		if ((float_t)y + result >= 0.0f)
		{
			player->SetPosition({ player->GetPosition().x, 0 });

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_Idle());
		}

		//keep falling
		else
		{
			player->Move(olc::vf2d{ 0.0f, result });
		}
	}
}