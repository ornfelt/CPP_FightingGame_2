#include "Player.h"

#include "StateMachineBase.h"

namespace RB::Players
{
	Player::~Player()
	{
		//std::cout << "destroying player: " << static_cast<int>(_playerID) << std::endl;

		delete _stateMachine;

		_stateMachine = nullptr;
	}

	void Player::Init(PlayerID id, RB::States::iState* firstPlayerState)
	{
		if (firstPlayerState == nullptr)
		{
			std::cout << "WARNING: firstPlayerState is nullptr" << std::endl;
		}
		else
		{
			_playerID = id;

			_stateMachine = new RB::States::StateMachineBase();
			_stateMachine->Init(firstPlayerState);

			_playerCollider.Init(this);

			//std::cout << "init player: " << static_cast<int>(_playerID) << std::endl;
		}
	}

	void Player::OnUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		_stateMachine->OnUpdate();

		_playerCollider.OnUpdate();
	}

	void Player::OnFixedUpdate()
	{
		_stateMachine->OnFixedUpdate();

		_playerCollider.OnFixedUpdate();
	}

	PlayerID Player::GetPlayerID()
	{
		return _playerID;
	}

	void Player::SetCharacterType(CharacterType type)
	{
		_characterType = type;
	}

	CharacterType Player::GetCharacterType()
	{
		return _characterType;
	}

	iPlayerCollider* Player::GetPlayerCollider()
	{
		return &_playerCollider;
	}

	int Player::GetPlayerID_int()
	{
		if (_playerID == RB::Players::PlayerID::PLAYER_1)
		{
			return 1;
		}
		else if (_playerID == RB::Players::PlayerID::PLAYER_2)
		{
			return 2;
		}

		return 0;
	}

	/// <summary>
	/// This is different from OtherPlayerIsOnRightSide
	/// You can be facing right side while the enemy is on your left
	/// </summary>
	bool Player::IsFacingRight()
	{
		if (_dirIsFixedDuringState)
		{
			return _initiallyFacingRight;
		}

		return OtherPlayerIsOnRightSide();
	}

	bool Player::OtherPlayerIsOnRightSide()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return true;
		}

		iPlayer* other = RB::Players::iPlayerController::Get()->GetOtherPlayer(this);

		if (other == nullptr)
		{
			return true;
		}

		if (_position.x < other->GetPosition().x)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Player::InitiallyFacingRight()
	{
		return false;
	}

	void Player::InitiallyFacingRight(bool initiallyFacingRight)
	{
		_initiallyFacingRight = initiallyFacingRight;
	}

	RB::States::iStateMachine* Player::GetStateMachine()
	{
		return _stateMachine;
	}

	unsigned int Player::GetStateMachineID()
	{
		return _stateMachine->GetID();
	}

	void Player::Move(olc::vf2d moveAmount)
	{
		_position += moveAmount;
	}

	olc::vf2d Player::GetPosition()
	{
		return _position;
	}

	void Player::SetPosition(olc::vf2d pos)
	{
		_position = pos;
	}

	void Player::SetManualAnimationUpdate(bool manual)
	{
		_manualAnimationUpdate = manual;
	}

	bool Player::ManualAnimationUpdate()
	{
		return _manualAnimationUpdate;
	}

	void Player::SetWincingStatus(bool wincing)
	{
		_isWincing = wincing;
	}

	bool Player::IsWincing()
	{
		return _isWincing;
	}

	void Player::FixDirDuringState(bool fix)
	{
		_dirIsFixedDuringState = fix;
	}

	void Player::SetIsInSpecialMoveStatus(bool specialMove)
	{
		_isInSpecialMoveState = specialMove;
	}

	bool Player::IsInSpecialMoveStatus()
	{
		return _isInSpecialMoveState;
	}
}