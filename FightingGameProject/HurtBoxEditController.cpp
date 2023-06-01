#include "HurtBoxEditController.h"

namespace RB::HurtBox
{
	void HurtBoxEditController::Init()
	{

	}

	void HurtBoxEditController::OnUpdate()
	{
		_getter_playerController.OnUpdate();
		_getter_playerAnimationController.OnUpdate();
		_getter_hurtBoxDataController.OnUpdate();
		_getter_camController.OnUpdate();

		if (_getter_playerController.GetController() == nullptr ||
			_getter_playerAnimationController.GetController() == nullptr ||
			_getter_hurtBoxDataController.GetController() == nullptr ||
			_getter_camController.GetController() == nullptr)
		{
			return;
		}

		RB::HurtBox::HurtBoxDataSet* set = GetCurrentHurtBoxDataSet(RB::Players::PlayerID::PLAYER_1);
		RB::HurtBox::HurtBoxData* data = GetCurrentHurtBoxData(RB::Players::PlayerID::PLAYER_1);
		RB::Collisions::AABB* aabb = GetCurrentAABB(data);

		_SaveSet_OnPress(set);
		_AddAABB_OnPress(data);
		_RenderCircleOnAABB(aabb, RB::Players::PlayerID::PLAYER_1);
		_EditAABB_OnPress(aabb);

	}

	void HurtBoxEditController::OnFixedUpdate()
	{

	}

	RB::HurtBox::HurtBoxDataSet* HurtBoxEditController::GetCurrentHurtBoxDataSet(RB::Players::PlayerID playerID)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::PlayerAnimationObj* aniObj = _getter_playerAnimationController.GetController()->GetAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int32_t currentIndex = aniObj->GetCurrentIndex();
		RB::HurtBox::HurtBoxDataSet* dataSet = _getter_hurtBoxDataController.GetController()->GetDataSet(spriteEnum);

		return dataSet;
	}

	RB::HurtBox::HurtBoxData* HurtBoxEditController::GetCurrentHurtBoxData(RB::Players::PlayerID playerID)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::PlayerAnimationObj* aniObj = _getter_playerAnimationController.GetController()->GetAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int32_t currentIndex = aniObj->GetCurrentIndex();
		RB::HurtBox::HurtBoxDataSet* dataSet = _getter_hurtBoxDataController.GetController()->GetDataSet(spriteEnum);
		RB::HurtBox::HurtBoxData* data = dataSet->GetHurtBoxDataByFrame(currentIndex);

		return data;
	}

	RB::Collisions::AABB* HurtBoxEditController::GetCurrentAABB(RB::HurtBox::HurtBoxData* data)
	{
		size_t count = data->GetAABBCount();

		_UpdateSelectedIndex(count);

		for (size_t i = 0; i < count; i++)
		{
			if (i == _selectedIndex)
			{
				RB::Collisions::AABB& aabb = data->GetAABB(i);

				return &aabb;
			}
		}

		return nullptr;
	}

	void HurtBoxEditController::_AddAABB_OnPress(RB::HurtBox::HurtBoxData* data)
	{
		olc::HWButton insButton = olc::Platform::ptrPGE->GetKey(olc::INS);
		olc::HWButton delButton = olc::Platform::ptrPGE->GetKey(olc::DEL);

		if (insButton.bPressed)
		{
			data->AddAABB(RB::Collisions::AABB{ -25.0f, 25.0f, 50.0f, 50.0f });

			_selectedIndex = data->GetAABBCount() - 1;
		}

		if (delButton.bPressed)
		{
			if (data->DeleteAABB(_selectedIndex))
			{
				_selectedIndex--;
			}
		}
	}

	void HurtBoxEditController::_RenderCircleOnAABB(RB::Collisions::AABB* aabb, RB::Players::PlayerID playerID)
	{
		RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		olc::vf2d pos = player->GetPosition() + aabb->GetBottomLeft();

		olc::vi2d relPos = _getter_camController.GetController()->GetCamObj()->GetRelativePosition(pos) + olc::vi2d{1, -1};

		olc::Renderer::ptrPGE->DrawCircle(relPos, 3, olc::WHITE);
		olc::Renderer::ptrPGE->DrawCircle(relPos, 4, olc::WHITE);
	}

	void HurtBoxEditController::_EditAABB_OnPress(RB::Collisions::AABB* aabb)
	{
		if (aabb == nullptr)
		{
			return;
		}

		olc::HWButton wButton = olc::Platform::ptrPGE->GetKey(olc::W);
		olc::HWButton sButton = olc::Platform::ptrPGE->GetKey(olc::S);

		olc::HWButton aButton = olc::Platform::ptrPGE->GetKey(olc::A);
		olc::HWButton dButton = olc::Platform::ptrPGE->GetKey(olc::D);

		float_t moveAmount = 50.0f;

		if (wButton.bHeld)
		{
			aabb->MoveY(-moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (sButton.bHeld)
		{
			aabb->MoveY(moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (aButton.bHeld)
		{
			aabb->MoveX(-moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (dButton.bHeld)
		{
			aabb->MoveX(moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		olc::HWButton uButton = olc::Platform::ptrPGE->GetKey(olc::U);
		olc::HWButton jButton = olc::Platform::ptrPGE->GetKey(olc::J);

		olc::HWButton hButton = olc::Platform::ptrPGE->GetKey(olc::H);
		olc::HWButton kButton = olc::Platform::ptrPGE->GetKey(olc::K);

		float_t sizeAmount = 40.0f;

		if (uButton.bHeld)
		{
			aabb->IncreaseHeight(sizeAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (jButton.bHeld)
		{
			aabb->IncreaseHeight(-sizeAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (hButton.bHeld)
		{
			aabb->IncreaseWidth(-sizeAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (kButton.bHeld)
		{
			aabb->IncreaseWidth(sizeAmount * RB::Frames::Time::GetDeltaTime());
		}
	}

	void HurtBoxEditController::_UpdateSelectedIndex(size_t count)
	{
		olc::HWButton oButton = olc::Platform::ptrPGE->GetKey(olc::O);
		olc::HWButton pButton = olc::Platform::ptrPGE->GetKey(olc::P);

		if (oButton.bPressed)
		{
			_selectedIndex--;
		}

		if (pButton.bPressed)
		{
			_selectedIndex++;
		}

		if (_selectedIndex == SIZE_MAX)
		{
			_selectedIndex = count - 1;
		}
		else if (_selectedIndex >= count)
		{
			_selectedIndex = 0;
		}
	}
	void HurtBoxEditController::_SaveSet_OnPress(RB::HurtBox::HurtBoxDataSet* set)
	{
		olc::HWButton enterButton = olc::Platform::ptrPGE->GetKey(olc::ENTER);

		if (enterButton.bPressed)
		{
			std::cout << std::endl;
			std::cout << "saving hurtbox set" << std::endl;

			std::string path = "HurtBoxSpecs/TestSave.HurtBoxSpecs";

			std::ofstream file(path);

			if (file.is_open())
			{
				//start of whole obj
				file << "{" << std::endl;

				for (size_t i = 0; i < set->GetSize(); i++)
				{
					HurtBoxData* data = set->GetHurtBoxDataByFrame(i);
					const std::string& frameName = data->GetFrameName();

					file << "    " << frameName << "\":" << std::endl;
				}

				//end of whole obj
				file << "}";

				file.flush();
				file.close();
			}
		}
	}
}