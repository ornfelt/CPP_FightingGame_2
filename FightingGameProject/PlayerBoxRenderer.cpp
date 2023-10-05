#include "PlayerBoxRenderer.h"

namespace RB::Render
{
    void PlayerBoxRenderer::Init(SpriteObj* spriteRenderer)
	{
		_spriteObj = spriteRenderer;
	}

	void PlayerBoxRenderer::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		for (int32_t i = 0; i < 2; i++)
		{
			RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnIndex(i);

			if (player == nullptr)
			{
				continue;
			}

			olc::vi2d playerBox = player->GetPlayerBox();
			olc::vi2d playerPos = player->GetPosition();

			olc::Pixel boxTint = olc::YELLOW;

			if (player->IsCollidingAgainstOtherPlayer())
			{
				boxTint = olc::BLUE;
			}

			_spriteObj->RenderSprite(RB::Sprites::SpriteEnum::white_sq_tr80, playerBox, playerPos, boxTint, RB::Sprites::PivotType::BOTTOM_CENTER);
		}
	}

	void PlayerBoxRenderer::OnFixedUpdate()
	{

	}
}