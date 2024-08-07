#pragma once

#include "SpriteType.h"
#include "AttackStrengthType.h"

namespace RB::Collisions
{
	class AttackSpecs
	{
		public:
			AttackSpecs() = default;
			~AttackSpecs() = default;

			RB::Sprites::SpriteType mSpriteType = RB::Sprites::SpriteType::NONE;
			RB::Collisions::AttackStrengthType mAttackStrengthType = RB::Collisions::AttackStrengthType::NONE;
			int mDamage = 0;
			int mHitStop = 0;
			int mMinimumFixedUpdatesSinceHit = 0;
			int mMaxHits = 0;
	};
}
