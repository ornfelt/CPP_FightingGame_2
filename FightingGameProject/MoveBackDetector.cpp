#include "MoveBackDetector.h"

namespace RB::PlayerStateComponents
{
	void MoveBack::SetStateMachineID(size_t id)
	{
		_stateMachineID = id;
	}

	void MoveBack::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Input::INPUT_CONTROLLER == nullptr)
		{
			return;
		}

		//false by default
		_moveBack = false;

		if (_BothPressed())
		{
			_moveBack = false;

			return;
		}

		if (_MoveBackPressed())
		{
			_moveBack = true;

			return;
		}
	}

	bool MoveBack::ProcMoveBack()
	{
		return _moveBack;
	}

	bool MoveBack::_BothPressed()
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		olc::HWButton moveLeft = RB::Input::INPUT_CONTROLLER->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Input::INPUT_CONTROLLER->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (moveLeft.bPressed && moveRight.bPressed)
		{
			return true;
		}

		if (moveLeft.bHeld && moveRight.bHeld)
		{
			return true;
		}

		return false;
	}

	bool MoveBack::_MoveBackPressed()
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		if (player == nullptr)
		{
			return false;
		}

		olc::HWButton moveLeft = RB::Input::INPUT_CONTROLLER->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Input::INPUT_CONTROLLER->GetButton(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (player->OtherPlayerIsOnRightSide())
		{
			if (moveLeft.bPressed || moveLeft.bHeld)
			{
				return true;
			}
		}
		else
		{
			if (moveRight.bPressed || moveRight.bHeld)
			{
				return true;
			}
		}

		return false;
	}
}