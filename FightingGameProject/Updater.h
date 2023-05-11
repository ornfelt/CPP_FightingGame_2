#pragma once
#include <iostream>
#include "iUpdaterObj.h"
#include "GameplayUpdater.h"

namespace RB::Updaters
{
	class Updater
	{
	public:
		Updater();
		~Updater();

	public:
		void SetUpdaterObj(iUpdaterObj* updaterObj);
		void QueueUpdaterObj(iUpdaterObj* updaterObj);
		void MakeUpdaterTransition();

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		bool _firstUpdaterInitialized = false;
		bool _updaterIsQueued = false;
		iUpdaterObj* _updaterObj = nullptr;
		iUpdaterObj* _nextUpdaterObj = nullptr;
	};
}