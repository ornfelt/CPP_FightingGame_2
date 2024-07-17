#pragma once

#include "StateComponentBase.h"

#include "SpriteType.h"
#include "CollisionResult.h"

#include "iPlayer.h"

namespace RB::PlayerStateComponents
{
	class DetectHit : public RB::States::StateComponentBase
	{
	public:
		DetectHit() = default;
		~DetectHit() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		void _ProcessHit();
		bool _HitDetected(RB::Collisions::CollisionResult& collisionResult);
		void _RegisterHit(RB::Collisions::CollisionResult& collisionResult);
		void _AddFixedUpdatesSinceLastHit();

		int _hits = 0;
		int _fixedUpdatesSinceLastHit = 0;
	};
}
