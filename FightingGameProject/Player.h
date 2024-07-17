#pragma once

#include "CharacterType.h"
#include "PlayerID.h"
#include "PlayerCollider.h"
#include "StateMachineBase.h"

#include "iPlayerCollider.h"
#include "iPlayer.h"
#include "iState.h"
#include "iStateMachine.h"

namespace RB::Players
{
	class Player : public iPlayer
	{
	public:
		Player() = default;
		~Player() override;

	public:
		void Init(PlayerID id, RB::States::iState* firstPlayerState) override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		PlayerID GetPlayerID() override;
		void SetCharacterType(CharacterType type) override;
		CharacterType GetCharacterType() override;
		iPlayerCollider* GetPlayerCollider() override;
		int GetPlayerID_int() override;
		bool IsFacingRight() override;
		bool OtherPlayerIsOnRightSide() override;
		bool InitiallyFacingRight() override;
		void InitiallyFacingRight(bool initiallyFacingRight) override;
		RB::States::iStateMachine* GetStateMachine() override;
		unsigned int GetStateMachineID() override;
		void Move(RB::Vector2 moveAmount) override;
		RB::Vector2 GetPosition() override;
		void SetPosition(RB::Vector2 pos) override;
		void SetManualAnimationUpdate(bool manual) override;
		bool ManualAnimationUpdate() override;
		void SetWincingStatus(bool wincing) override;
		bool IsWincing() override;
		void FixDirDuringState(bool fix) override;
		void SetIsInSpecialMoveStatus(bool specialMove) override;
		bool IsInSpecialMoveStatus() override;

	protected:
		PlayerID _playerID = PlayerID::NONE;
		CharacterType _characterType = CharacterType::NONE;
		RB::States::iStateMachine* _stateMachine = nullptr;
		PlayerCollider _playerCollider;
		RB::Vector2 _position = { 0.0f, 0.0f };
		bool _manualAnimationUpdate = false;
		bool _initiallyFacingRight = false;
		bool _isWincing = false;
		bool _dirIsFixedDuringState = false;
		bool _isInSpecialMoveState = false;
	};
}
