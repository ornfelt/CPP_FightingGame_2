#pragma once

#include "Vector2.h"
#include "Player.h"

#include "PlayerController.h"
#include "BackgroundController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "PlayerBoxDataController.h"
#include "SpecsController.h"
#include "InputController.h"
#include "SpecialMovesController.h"
#include "CamController.h"
#include "TargetBoxDataController.h"
#include "HBox/AttackBoxDataController.h"
#include "AttackRegisterController.h"
#include "GeneralHitStopController.h"
#include "AttackSpecsController.h"
#include "VFXAnimationController.h"

#include "iUpdaterObj.h"

#include "P0_Idle.h"

namespace RB::Updaters
{
	class GameplayUpdater : public iUpdaterObj
	{
	public:
		GameplayUpdater() = default;
		~GameplayUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
