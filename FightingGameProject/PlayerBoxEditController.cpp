#include "PlayerBoxEditController.h"

#include "PlayerState.h"

#include "iPlayerController.h"
#include "iPlayerBoxDataController.h"
#include "iPlayerAnimationController.h"
#include "iPlayerDebugController.h"

namespace RB::Collisions
{
	void PlayerBoxEditController::Init()
	{

	}

	void PlayerBoxEditController::OnUpdate()
	{
		PlayerBox* currentBox = _GetPlayerBox(RB::Players::PlayerID::PLAYER_1);

		if (currentBox == nullptr)
		{
			RB::Render::iPlayerDebugController::instance->RenderPlayerBox(false);
		}
		else
		{
			RB::Render::iPlayerDebugController::instance->RenderPlayerBox(true);
		}

		_UpdateBoxSizeOnPress(currentBox);
	}

	void PlayerBoxEditController::OnFixedUpdate()
	{

	}

	void PlayerBoxEditController::_UpdateBoxSizeOnPress(RB::Collisions::PlayerBox* box)
	{
		if (box == nullptr)
		{
			return;
		}


	}

	PlayerBox* PlayerBoxEditController::_GetPlayerBox(RB::Players::PlayerID id)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(id);

		RB::Players::CharacterType characterType = player->GetCharacterType();

		if (RB::Collisions::iPlayerBoxDataController::instance == nullptr)
		{
			return nullptr;
		}

		RB::Collisions::LoadedPlayerBoxData* loaded = RB::Collisions::iPlayerBoxDataController::instance->GetLoadedData(characterType);

		if (loaded == nullptr)
		{
			return nullptr;
		}

		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(id);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::iAnimationObj* iAniObj = RB::Render::iPlayerAnimationController::instance->GetCurrentAnimationObj(id, spriteEnum);

		if (iAniObj == nullptr)
		{
			return nullptr;
		}

		unsigned int animationIndex = iAniObj->GetCurrentIndex();

		RB::Collisions::PlayerBoxSpecs* specs = loaded->GetSpecs(spriteEnum, animationIndex);

		if (specs == nullptr)
		{
			return nullptr;
		}

		auto* box = specs->GetBox_ptr(animationIndex);

		if (box != nullptr)
		{
			return box;
		}
		else
		{
			return nullptr;
		}
	}
}