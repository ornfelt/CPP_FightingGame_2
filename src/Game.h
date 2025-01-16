#pragma once

#define OLC_PGE_APPLICATION 0

#include <iostream>

#include "olcPixelGameEngine.h"

#include "AllocationCount.h"
#include "GameFrame.h"
#include "Time.h"
#include "FixedTimer.h"
#include "UpdateCounter.h"
#include "DisplaySize.h"

#include "Render/RenderLayerType.h"
#include "Updaters/CurrentUpdater.h"
#include "Updaters/Updater.h"

namespace RB
{
	class Game : public olc::PixelGameEngine
	{
	private:
		RB::Updaters::iPlayground* _playground = nullptr;
		RB::FixedTimer _timer;
		RB::UpdateCounter _updateCounter;

	public:
		bool OnUserCreate() override
		{
			sAppName = "C++FightingGame2";
		
			_playground = new RB::Updaters::Updater();

			RB::Updaters::ptrCurrentPlayground = _playground;

			_playground->Init();

			//RB::Time::ResetFixedDeltaTime();

			RB::Render::CreateLayers();

			return true;
		}

		bool OnUserDestroy() override
		{
			delete _playground;

			return true;
		}

		~Game()
		{
			std::cout << std::endl;
			std::cout << "destructing game class.." << std::endl;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			if (_timer.DoFixedUpdate())
			{
				_playground->OnFixedUpdate();

				//RB::Time::ResetFixedDeltaTime();

				RB::AddGameFrame();
			}

			RB::Render::ClearLayers();

			RB::Time::SetDeltaTime(fElapsedTime);
			//RB::Time::AddFixedDeltaTime();

			_playground->OnUpdate();
			_updateCounter.OnUpdate();

			return true;
		}

		void Run()
		{
			if (Construct(displayWidth, displayHeight, 1, 1, false, false, false))
			{
				std::cout << "--- current working directory: " << std::filesystem::current_path() << " ---" << std::endl;
				std::cout << std::endl;

				Start();
			}
		}
	};
}