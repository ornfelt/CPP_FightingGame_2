#include "PlayerInputRenderer.h"

namespace RB::Render
{
	void PlayerInputRenderer::Init(Sprites* sprites)
	{
		_sprites = sprites;
	}

	void PlayerInputRenderer::OnUpdate()
	{
		_RenderPlayerInputIcons(RB::Players::PLAYER_CONTROLLER->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1));
	}

	void PlayerInputRenderer::OnFixedUpdate()
	{

	}

	void PlayerInputRenderer::_RenderPlayerInputIcons(RB::Players::iPlayer* player)
	{
		size_t count = RB::Input::INPUT_CONTROLLER->GetTotalInputCount(player->GetPlayerID());

		for (size_t i = 0; i < count; i++)
		{
			RB::Input::iInputObj* inputObj = RB::Input::INPUT_CONTROLLER->GetInputByIndex(player->GetPlayerID(), i);

			_RenderIcon(RB::Sprites::SpriteEnum::input_arrow_up, olc::vi2d(5 + (i * 25), 40), olc::WHITE);
		}
	}

	void PlayerInputRenderer::_RenderIcon(RB::Sprites::SpriteEnum spriteEnum, olc::vi2d pos, olc::Pixel tint)
	{
		_sprites->RenderSprite(spriteEnum, olc::vi2d{ 30, 30 }, pos, tint, RB::Sprites::PivotType::BOTTOM_LEFT, false);
	}
}