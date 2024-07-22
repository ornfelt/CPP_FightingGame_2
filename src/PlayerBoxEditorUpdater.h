#pragma once

#include "Vector2.h"
#include "Player.h"

#include "PlayerController.h"
#include "Render/PlayerAnimationController.h"
#include "Collisions/PlayerBoxDataController.h"
#include "CamController.h"
#include "Render/PlayerDebugController.h"
#include "InputController.h"
#include "Collisions/PlayerBoxEditController.h"

#include "Updaters/iUpdaterObj.h"

#include "P0_Dummy.h"

namespace RB::Updaters
{
	class PlayerBoxEditorUpdater : public iUpdaterObj
	{
	public:
		PlayerBoxEditorUpdater() = default;
		~PlayerBoxEditorUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
