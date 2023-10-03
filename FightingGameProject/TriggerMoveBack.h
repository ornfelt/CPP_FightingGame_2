#pragma once
#include "StateComponentBase.h"
#include "MoveBack.h"
#include "P0_MoveBack.h"

#include "iPlayerController.h"
#include "iPlayer.h"

namespace RB::PlayerStateComponents
{
	class TriggerMoveBack : public RB::States::StateComponentBase
	{
	public:
		TriggerMoveBack() = default;
		~TriggerMoveBack() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;

	private:
		MoveBack _moveBack;
	};
}