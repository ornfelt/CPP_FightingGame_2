#pragma once
#include "StateComponentBase.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class ToggleInitiallyFacingRight : public RB::States::StateComponentBase
	{
	public:
		ToggleInitiallyFacingRight(bool isFacingRight);
		~ToggleInitiallyFacingRight() override = default;

		void OnEnter() override;

	private:
		bool _facingRight = true;
	};
}