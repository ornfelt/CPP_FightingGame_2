#pragma once

#include "StateComponentBase.h"

#include "iState.h"
#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class TransitionOnFixedUpdateCount : public RB::States::StateComponentBase
	{
	public:
		TransitionOnFixedUpdateCount(int fixedUpdateOnCount, RB::States::iState* nextState);
		~TransitionOnFixedUpdateCount() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
