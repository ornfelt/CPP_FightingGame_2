#pragma once
#include "StateComponentBase.h"
#include "MoveBackDetector.h"
#include "MoveForwardDetector.h"
#include "Idle.h"

namespace RB::PlayerStateComponents
{
	class WhileMovingBack : public RB::States::StateComponentBase
	{
	public:
		WhileMovingBack();
		~WhileMovingBack() override;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		MoveBackDetector _moveBackDetector;
		MoveForwardDetector _moveForwardDetector;
		bool _keepMoving = false;
		bool _moveForward = false;
	};
}