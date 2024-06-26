#include "PlayerBoxEditController.h"

#include "PlayerState.h"
#include "Time.h"

#include "iPlayerController.h"
#include "iPlayerBoxDataController.h"
#include "iPlayerAnimationController.h"
#include "iPlayerDebugController.h"
#include "iSpriteDataController.h"

namespace RB::Collisions
{
	void PlayerBoxEditController::Init()
	{

	}

	void PlayerBoxEditController::OnUpdate()
	{
		_ShowMenu();

		PlayerBox* currentBox = _GetCurrentBox(RB::Players::PlayerID::PLAYER_1);

		if (currentBox == nullptr)
		{
			RB::Render::iPlayerDebugController::Get()->RenderPlayerBox(false);
		}
		else
		{
			RB::Render::iPlayerDebugController::Get()->RenderPlayerBox(true);
		}

		_UpdateBoxSizeOnPress(currentBox);
		_AddDeleteBoxOnPress(RB::Players::PlayerID::PLAYER_1);
		_SaveOnPress();
	}

	void PlayerBoxEditController::OnFixedUpdate()
	{

	}

	void PlayerBoxEditController::_UpdateBoxSizeOnPress(RB::Collisions::PlayerBox* currentBox)
	{
		if (currentBox == nullptr)
		{
			return;
		}

		olc::HWButton uButton = olc::Platform::ptrPGE->GetKey(olc::U);
		olc::HWButton jButton = olc::Platform::ptrPGE->GetKey(olc::J);

		olc::HWButton hButton = olc::Platform::ptrPGE->GetKey(olc::H);
		olc::HWButton kButton = olc::Platform::ptrPGE->GetKey(olc::K);

		float sizeAmount = 40.0f;

		if (uButton.bHeld)
		{
			currentBox->mHeight += sizeAmount * RB::Frames::Time::GetDeltaTime();
		}

		if (jButton.bHeld)
		{
			currentBox->mHeight -= sizeAmount * RB::Frames::Time::GetDeltaTime();
		}

		if (hButton.bHeld)
		{
			currentBox->mWidth -= sizeAmount * RB::Frames::Time::GetDeltaTime();
		}

		if (kButton.bHeld)
		{
			currentBox->mWidth += sizeAmount * RB::Frames::Time::GetDeltaTime();
		}

		if (currentBox->mHeight <= 0.0f)
		{
			currentBox->mHeight = 0.0f;
		}

		if (currentBox->mWidth <= 0.0f)
		{
			currentBox->mWidth = 0.0f;
		}
	}

	void PlayerBoxEditController::_AddDeleteBoxOnPress(RB::Players::PlayerID id)
	{
		PlayerBoxSpecs* currentSpecs = _GetCurrentSpecs(RB::Players::PlayerID::PLAYER_1);

		olc::HWButton insButton = olc::Platform::ptrPGE->GetKey(olc::INS);
		olc::HWButton delButton = olc::Platform::ptrPGE->GetKey(olc::DEL);

		if (insButton.bPressed)
		{
			if (currentSpecs == nullptr)
			{
				RB::Collisions::iPlayerBoxDataController::Get()->AddSpecs(PlayerBox(_GetCurrentFrame(id), 0.0f, 0.0f, 62.0f, 124.0f), _GetCurrentSpriteType(id), RB::Players::iPlayerController::Get()->GetPlayerOnID(id)->GetCharacterType());
			}
			else
			{
				PlayerBox* existingBox = currentSpecs->GetBox_ptr(_GetCurrentFrame(id));

				if (existingBox == nullptr)
				{
					currentSpecs->AddBox(PlayerBox(_GetCurrentFrame(id), 0.0f, 0.0f, 62.0f, 124.0f));
				}
				else
				{
					//do nothing - only one box per sprite for now
				}
			}
		}

		if (delButton.bPressed)
		{
			if (currentSpecs == nullptr)
			{
				//nothing to delete	
			}
			else
			{
				RB::Collisions::LoadedPlayerBoxData* loaded = RB::Collisions::iPlayerBoxDataController::Get()->GetLoadedData(_GetCharacterType(id));
				loaded->EraseSpecs(_GetCurrentSpriteType(id), _GetCurrentFrame(id));
				loaded->RefreshIterators();
			}
		}
	}

	void PlayerBoxEditController::_SaveOnPress()
	{
		olc::HWButton enter = olc::Platform::ptrPGE->GetKey(olc::ENTER);

		if (enter.bPressed)
		{
			PlayerBoxSpecs* specs = _GetCurrentSpecs(RB::Players::PlayerID::PLAYER_1);

			if (specs == nullptr)
			{
				return;
			}

			specs->Save();
		}
	}

	void PlayerBoxEditController::_ShowMenu()
	{
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 320, 20 }, "PlayerBoxEditor", olc::WHITE, 2);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 80 }, "PgUp, PgDown : prev/next frame", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 100 }, "Ins, Del : create/delete box", olc::WHITE);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 160 }, "UHJK : enlarge/shrink box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 180 }, "ENTER : save data", olc::WHITE);

		const std::string& str = RB::Sprites::iSpriteDataController::Get()->GetString(_GetCurrentSpriteType(RB::Players::PlayerID::PLAYER_1));
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 260 }, "current animation: " + str, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 280 }, "current animation frame: " + std::to_string(_GetCurrentFrame(RB::Players::PlayerID::PLAYER_1)), olc::YELLOW);
	}

	PlayerBox* PlayerBoxEditController::_GetCurrentBox(RB::Players::PlayerID id)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnID(id);
	
		RB::Players::CharacterType characterType = player->GetCharacterType();
	
		if (RB::Collisions::iPlayerBoxDataController::Get() == nullptr)
		{
			return nullptr;
		}
	
		RB::Collisions::LoadedPlayerBoxData* loaded = RB::Collisions::iPlayerBoxDataController::Get()->GetLoadedData(characterType);
	
		if (loaded == nullptr)
		{
			return nullptr;
		}
	
		RB::Collisions::PlayerBox* box = loaded->GetSpecs(_GetCurrentSpriteType(id), _GetCurrentFrame(id));
	
		return box;
	}

	PlayerBoxSpecs* PlayerBoxEditController::_GetCurrentSpecs(RB::Players::PlayerID id)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnID(id);

		RB::Players::CharacterType characterType = player->GetCharacterType();

		if (RB::Collisions::iPlayerBoxDataController::Get() == nullptr)
		{
			return nullptr;
		}

		RB::Collisions::LoadedPlayerBoxData* loaded = RB::Collisions::iPlayerBoxDataController::Get()->GetLoadedData(characterType);

		if (loaded == nullptr)
		{
			return nullptr;
		}

		RB::Collisions::PlayerBoxSpecs* specs = loaded->GetSpecs(_GetCurrentSpriteType(id));

		return specs;
	}

	RB::Players::CharacterType PlayerBoxEditController::_GetCharacterType(RB::Players::PlayerID id)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnID(id);

		RB::Players::CharacterType characterType = player->GetCharacterType();

		return characterType;
	}

	RB::Sprites::SpriteType PlayerBoxEditController::_GetCurrentSpriteType(RB::Players::PlayerID id)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(id);

		if (state == nullptr)
		{
			return RB::Sprites::SpriteType::NONE;
		}

		RB::Sprites::SpriteType spriteType = state->GetSpriteType();

		return spriteType;
	}

	unsigned int PlayerBoxEditController::_GetCurrentFrame(RB::Players::PlayerID id)
	{
		RB::Sprites::SpriteType spriteType = _GetCurrentSpriteType(id);

		RB::Render::iAnimationObj* iAniObj = RB::Render::iPlayerAnimationController::Get()->GetCurrentAnimationObj(id, spriteType);

		if (iAniObj == nullptr)
		{
			return 0;
		}

		unsigned int animationIndex = iAniObj->GetCurrentIndex();

		return animationIndex;
	}
}