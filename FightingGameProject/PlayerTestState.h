#pragma once
#include "StateBase.h"
//#include "GameplayControllers.h"
//#include "iPlayer.h"
//#include "iController.h"

//using namespace RB::States;
//using namespace RB::Controllers;
//using namespace RB::Players;

namespace RB::Players
{
	//class iPlayer;
	//class GameplayControllers;

	//class RB::Controllers::GameplayControllers;

	class PlayerTestState : public RB::States::StateBase
	{
	public:
		~PlayerTestState() override;

		void OnFixedUpdate() override;
	};
}