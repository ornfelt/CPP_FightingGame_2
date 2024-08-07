#pragma once
#define OLC_PGE_APPLICATION 0

#include <iostream>

#include "olcPixelGameEngine.h"

#include "AllocationCount.h"
#include "GameFrame.h"
#include "Updater.h"
#include "Time.h"
#include "FixedTimer.h"
#include "RenderTimer.h"
#include "DisplaySize.h"
#include "RenderLayerType.h"
#include "CurrentUpdater.h"

namespace RB
{
	class Game : public olc::PixelGameEngine
	{
	private:
		RB::Updaters::iUpdater* _updater = nullptr;
		RB::Frames::FixedTimer _timer;
		RB::Frames::RenderTimer _renderTimer;

	public:
		bool OnUserCreate() override
		{
			sAppName = "C++FightingGame2";
		
			_updater = new RB::Updaters::Updater();

			RB::Updaters::ptrCurrentUpdater = _updater;

			_updater->Init();

			RB::Frames::Time::ResetFixedDeltaTime();

			RB::Render::CreateLayers();

			return true;
		}

		bool OnUserDestroy() override
		{
			delete _updater;

			return true;
		}

		~Game()
		{
			std::cout << std::endl;
			std::cout << "destructing game class.. showing allocation count.." << std::endl;

			showAllocCount = true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			if (_timer.DoFixedUpdate())
			{
				_updater->OnFixedUpdate();

				RB::Frames::Time::ResetFixedDeltaTime();

				RB::AddGameFrame();
			}

			RB::Render::ClearLayers();

			RB::Frames::Time::SetDeltaTime(fElapsedTime);
			RB::Frames::Time::AddFixedDeltaTime();

			_updater->OnUpdate();
			_renderTimer.OnUpdate();

			return true;
		}

		void Run()
		{
			if (Construct(displayWidth, displayHeight, 1, 1, false, false, false))
			{
				Start();
			}
		}
	};
}
