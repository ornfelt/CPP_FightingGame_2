#pragma once
#include "iGeneralHitStopController.h"

namespace RB::Collisions
{
	class GeneralHitStopController : public iGeneralHitStopController
	{
	public:
		GeneralHitStopController();
		~GeneralHitStopController() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		bool SkipFrame() override;
		void AddSkipFrames(uint32_t frames);

	private:
		uint32_t _skipFrames = 0;
	};
}