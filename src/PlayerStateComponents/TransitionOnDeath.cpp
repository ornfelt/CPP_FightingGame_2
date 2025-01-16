#include "TransitionOnDeath.h"

#include "../Updaters/CurrentPlayground.h"

namespace RB::PlayerStateComponents
{
	TransitionOnDeath::TransitionOnDeath(int fixedUpdateOnCount, RB::States::iState* nextState)
	{
		_fixedUpdateOnCount = fixedUpdateOnCount;
		_vecNextStates.push_back(nextState);
	}
	void TransitionOnDeath::OnEnter()
	{

	}

	void TransitionOnDeath::OnUpdate()
	{

	}

	void TransitionOnDeath::OnFixedUpdate()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player->GetHP() <= 0)
		{
			Updaters::ptrCurrentPlayground->SetFixedUpdateSkips(6);
			Updaters::ptrCurrentPlayground->ClearFixedUpdateSkip(10);

			player->GetStateMachine()->QueueNextState(_vecNextStates[0]);
		}
	}
}