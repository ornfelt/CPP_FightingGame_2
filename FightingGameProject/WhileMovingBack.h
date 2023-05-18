#pragma once
#include "StateComponentBase.h"
#include "MoveBackDetector.h"
#include "MoveForwardDetector.h"
#include "P0_Idle.h"
#include "P0_MoveForward.h"
#include "iPlayer.h"

#include "ControllerGetter.h"
#include "PlayerController.h"

namespace RB::PlayerStateComponents
{
	class WhileMovingBack : public RB::States::StateComponentBase
	{
	public:
		WhileMovingBack() = default;
		~WhileMovingBack() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		MoveBackDetector _moveBackDetector;
		MoveForwardDetector _moveForwardDetector;
		bool _keepMoving = false;
		bool _moveForward = false;

	private:
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
	};
}