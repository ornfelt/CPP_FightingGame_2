#pragma once

#include "olcPixelGameEngine.h"

#include "Vector2.h"
#include "SpriteContainer.h"

#include "iPlayerController.h"

namespace RB::Render
{
	class PlayerBoxRenderer
	{
	public:
		PlayerBoxRenderer() = default;
		~PlayerBoxRenderer() = default;

	public:
		void Init(RB::Sprites::SpriteContainer* spriteContainer);
		void OnUpdate();
		void OnFixedUpdate();

		void RenderPlayerBox(bool render);

	private:
		RB::Sprites::SpriteContainer* _spriteContainer = nullptr;
		bool _renderPlayerBox = true;
	};
}
