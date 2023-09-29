#pragma once
#include "HBoxDataList.h"
#include "AABB.h"
#include "PlayerID.h"
#include "Time.h"
#include "HBoxType.h"

#include "PlayerState.h"
#include "ActivePlayerStates.h"
#include "iPlayerAnimationObj.h"

#include "iHBoxEditController.h"
#include "iPlayerAnimationController.h"
#include "iHurtBoxDataController.h"
#include "iHitBoxDataController.h"
#include "iCamController.h"
#include "iMenuController.h"

namespace RB::HBox
{
	class HBoxEditControllerBase : public RB::HBox::iHBoxEditController
	{
	public:
		HBoxEditControllerBase(RB::HBox::HBoxType boxType);
		~HBoxEditControllerBase() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		RB::HBox::HBoxDataList* GetCurrentHBoxDataList(RB::Players::PlayerID playerID, HBoxType boxType) override;
		RB::HBox::HBoxData* GetCurrentHBoxData(RB::Players::PlayerID playerID) override;
		RB::Collisions::AABB* GetCurrentAABB(RB::HBox::HBoxData* data) override;
		RB::HBox::HBoxType GetHBoxType() override;

	private:
		bool _ControllersExist();
		void _UpdateSelectedIndex_OnPress(size_t count);
		void _RenderCircleOnAABB(RB::Players::PlayerID playerID);
		void _Add_Delete_AABB_OnPress();
		void _EditAABB_OnPress(RB::Players::PlayerID playerID);
		void _SaveHBoxes_OnPress();

	private:
		size_t _selectedIndex = 0;
		RB::HBox::HBoxType _boxType = RB::HBox::HBoxType::NONE;
	};
}