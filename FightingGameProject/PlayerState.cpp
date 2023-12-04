#include "PlayerState.h"

namespace RB::PlayerStates
{
	std::vector<PlayerState*> PlayerState::currentPlayerStates;
	size_t PlayerState::playerStateCreationCount = 0;

	PlayerState* PlayerState::GetPlayerState(RB::Players::PlayerID playerID)
	{
		for (size_t i = 0; i < currentPlayerStates.size(); i++)
		{
			RB::Players::iPlayer* owner = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(currentPlayerStates[i]->GetStateMachineID());

			if (owner != nullptr)
			{
				if (playerID == owner->GetPlayerID())
				{
					return currentPlayerStates[i];
				}
			}
		}

		return nullptr;
	}

	PlayerState::PlayerState()
	{
		playerStateCreationCount++;
		_creationID = playerStateCreationCount;

		currentPlayerStates.push_back(this);
	}

	PlayerState::~PlayerState()
	{
		for (int32_t i = currentPlayerStates.size() - 1; i >= 0; i--)
		{
			if (_creationID == currentPlayerStates[i]->GetCreationID())
			{
				currentPlayerStates[i] = nullptr;
				currentPlayerStates.erase(currentPlayerStates.begin() + i);
				break;
			}
		}	

		for (size_t i = 0; i < _vecStateComponents.size(); i++)
		{
			delete _vecStateComponents[i];
		}

		_vecStateComponents.clear();
	}

	RB::Players::iPlayer* PlayerState::GetPlayer()
	{
		return RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		return nullptr;
	}

	//void PlayerState::StandardInit(RB::Sprites::SpriteEnum spriteEnum)
	//{
	//	_spriteEnum = spriteEnum;
	//
	//	_ownerPlayer = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);
	//}

	RB::Sprites::SpriteEnum PlayerState::GetSpriteEnum()
	{
		return _spriteEnum;
	}

	//RB::Players::PlayerID PlayerState::GetPlayerID()
	//{
	//	RB::Players::iPlayer* player = GetPlayer();
	//
	//	return player->GetPlayerID();
	//}

	size_t PlayerState::GetCreationID()
	{
		return _creationID;
	}
}