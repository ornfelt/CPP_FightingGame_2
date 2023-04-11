#include "PlayerDebugController.h"

namespace RB::PlayerDebug
{
	PlayerDebugController::PlayerDebugController()
	{

	}

	PlayerDebugController::~PlayerDebugController()
	{

	}

	void PlayerDebugController::Init()
	{
		RB::Players::iPlayerController* pc = RB::Controllers::ControllerGroup::FindController<RB::Players::iPlayerController>();

		if (pc != nullptr)
		{
			_vecPlayers.push_back(pc->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1));
			_vecPlayers.push_back(pc->GetPlayerOnID(RB::Players::PlayerID::PLAYER_2));
		}
	}

	void PlayerDebugController::OnUpdate()
	{
		for (int i = 0; i < _vecPlayers.size(); i++)
		{
			DrawXOnPlayer(_vecPlayers[i]);
		}
	}

	void PlayerDebugController::OnFixedUpdate()
	{

	}

	void PlayerDebugController::DrawXOnPlayer(RB::Players::iPlayer* player)
	{
		olc::vi2d playerPos = player->GetPosition();

		RB::Controllers::GameplayControllers::DEBUG_RENDER_CONTROLLER->GetSpriteRenderer()->
			RenderSprite(olc::vi2d{ 12, 12 }, playerPos, olc::RED, RB::Sprites::PivotType::CENTER);
	}
}