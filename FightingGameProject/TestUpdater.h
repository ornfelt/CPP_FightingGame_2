#pragma once
#include <iostream>
#include "iUpdater.h"

namespace RB::Engine
{
	class TestUpdater : public iUpdater
	{
	public:
		TestUpdater();
		~TestUpdater() override;

		void OnUpdate() override;
	};
}