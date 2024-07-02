#include "PlayerDebugController.h"

namespace RB::Render
{
	void PlayerDebugController::Init()
	{
		_spriteContainer.LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteType::x_white);
		_spriteContainer.LoadSprite("PNG files/DebugElements/white_sq_tr80.png", RB::Sprites::SpriteType::white_sq_tr80);

		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_up.png", RB::Sprites::SpriteType::input_arrow_up);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_down.png", RB::Sprites::SpriteType::input_arrow_down);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_left.png", RB::Sprites::SpriteType::input_arrow_left);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_right.png", RB::Sprites::SpriteType::input_arrow_right);

		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_up_left.png", RB::Sprites::SpriteType::input_arrow_up_left);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_up_right.png", RB::Sprites::SpriteType::input_arrow_up_right);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_down_left.png", RB::Sprites::SpriteType::input_arrow_down_left);
		_spriteContainer.LoadSprite("PNG files/InputIcons/arrow_down_right.png", RB::Sprites::SpriteType::input_arrow_down_right);

		_spriteContainer.LoadSprite("PNG files/InputIcons/weak_punch.png", RB::Sprites::SpriteType::input_weak_punch);
		_spriteContainer.LoadSprite("PNG files/InputIcons/strong_punch.png", RB::Sprites::SpriteType::input_strong_punch);

		_spriteContainer.LoadSprite("PNG files/InputIcons/weak_kick.png", RB::Sprites::SpriteType::input_weak_kick);
		_spriteContainer.LoadSprite("PNG files/InputIcons/strong_kick.png", RB::Sprites::SpriteType::input_strong_kick);

		_playerBoxRenderer.Init(&_spriteContainer);
		_playerHBoxRenderer.Init(&_spriteContainer);
		_playerPositionRenderer.Init(&_spriteContainer, &_lineRenderer);
		_playerInputRenderer.Init(&_spriteContainer);
	}

	void PlayerDebugController::OnUpdate()
	{
		_playerBoxRenderer.OnUpdate();
		_playerHBoxRenderer.OnUpdate();
		_playerPositionRenderer.OnUpdate();
		_playerInputRenderer.OnUpdate();
	}

	void PlayerDebugController::OnFixedUpdate()
	{
		_playerBoxRenderer.OnFixedUpdate();
		_playerHBoxRenderer.OnFixedUpdate();
		_playerPositionRenderer.OnFixedUpdate();
		_playerInputRenderer.OnFixedUpdate();
	}

	void PlayerDebugController::RenderPlayerBox(bool render)
	{
		_playerBoxRenderer.RenderPlayerBox(render);
	}
}