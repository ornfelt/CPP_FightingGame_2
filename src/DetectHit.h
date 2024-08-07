#pragma once

#include <string>

#include "SpriteType.h"
#include "AttackSpecs.h"
#include "PlayerState.h"
#include "CollisionResult.h"
#include "StateComponentBase.h"

#include "iPlayer.h"
#include "iPlayerController.h"
#include "iPlayerAnimationController.h"
#include "iTargetBoxDataController.h"
#include "HBox/iAttackBoxDataController.h"
#include "iAttackRegisterController.h"
#include "iAttackSpecsController.h"

#include "P0_Wince.h"

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
