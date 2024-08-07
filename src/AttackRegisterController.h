#pragma once

#include <vector>

#include "SpriteType.h"
#include "AttackSpecs.h"
#include "RenderScaleMultiplierObj.h"

#include "P0_Wince.h" //temp
#include "P0_Strong_Wince.h" //temp

#include "iAttackSpecsController.h"
#include "iAnimationObj.h"
#include "iVFXAnimationController.h"
#include "iGeneralHitStopController.h"
#include "iAttackRegisterController.h"

namespace RB::Collisions
{
	class AttackRegisterController : public iAttackRegisterController
	{
	public:
		AttackRegisterController() = default;
		~AttackRegisterController() override = default;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void RegisterAttack(AttackRegister reg) override;
	};
}
