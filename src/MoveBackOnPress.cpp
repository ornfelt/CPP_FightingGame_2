#include "MoveBackOnPress.h"

namespace RB::PlayerStateComponents
{
	void MoveBackOnPress::SetStateMachineID(unsigned int id)
	{
		_stateMachineID = id;
	}

	void MoveBackOnPress::OnUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr ||
			RB::Input::iInputController::Get() == nullptr)
		{
			return;
		}

		//false by default
		_bMoveBack = false;

		if (_BothPressed())
		{
			_bMoveBack = false;

			return;
		}

		if (_MoveBackPressed())
		{
			_bMoveBack = true;

			return;
		}
	}

	bool MoveBackOnPress::ProcMoveBack()
	{
		return _bMoveBack;
	}

	bool MoveBackOnPress::_BothPressed()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		bool moveLeftHeld = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		bool moveRightHeld = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (moveLeftHeld && moveRightHeld)
		{
			return true;
		}

		return false;
	}

	bool MoveBackOnPress::_MoveBackPressed()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		bool moveLeftHeld = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		bool moveRightHeld = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (player->OtherPlayerIsOnRightSide())
		{
			if (moveLeftHeld)
			{
				return true;
			}
		}
		else
		{
			if (moveRightHeld)
			{
				return true;
			}
		}

		return false;
	}
}
