#pragma once
#include "olcPixelGameEngine.h"
#include "AABB.h"

#include "SpriteLoader.h"
#include "LineRenderer.h"

#include "iPlayerController.h"

namespace RB::Render
{
	class PlayerPositionRenderer
	{
	public:
		PlayerPositionRenderer() = default;
		~PlayerPositionRenderer() = default;

	public:
		void Init(RB::Sprites::SpriteLoader* spriteLoader, LineRenderer* lineRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderPosition(RB::Players::PlayerID playerID);
		void RenderBottomLeft(RB::Players::PlayerID playerID);

	private:
		RB::Sprites::SpriteLoader* _spriteLoader = nullptr;
		LineRenderer* _lineRenderer = nullptr;
	};
}
