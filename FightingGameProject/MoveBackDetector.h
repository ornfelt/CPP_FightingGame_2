#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"

#include "ControllerGetter.h"
#include "InputController.h"

namespace RB::PlayerStateComponents
{
	class MoveBackDetector
	{
	public:
		MoveBackDetector() = default;
		~MoveBackDetector() = default;

	public:
		void SetOwnerPlayer(RB::Players::iPlayer* player);
		void OnUpdate();
		bool MoveBack();

	private:
		bool _BothPressed();
		bool _MoveBackPressed();

	private:
		RB::Players::iPlayer* _player = nullptr;
		olc::HWButton moveLeft;
		olc::HWButton moveRight;
		bool _moveBack = false;

	private:
		RB::Controllers::ControllerGetter<RB::Input::InputController> _getter_inputController;
	};
}