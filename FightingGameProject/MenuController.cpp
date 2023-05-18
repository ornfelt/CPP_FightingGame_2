#include "MenuController.h"

namespace RB::HurtBox
{
	MenuController::MenuController()
	{
		SetHash(typeid(*this));
	}

	void MenuController::Init()
	{

	}

	void MenuController::OnUpdate()
	{
		_getter_pAniController.OnUpdate();
		_getter_PlayerController.OnUpdate();
		_getter_SprDataController.OnUpdate();

		if (_getter_pAniController.GetController() == nullptr ||
			_getter_PlayerController.GetController() == nullptr ||
			_getter_SprDataController.GetController() == nullptr)
		{
			return;
		}

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 320, 20 }, "HurtBoxEditor", olc::WHITE, 2);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 80 }, "PgUp, PgDown : prev/next frame", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 100 }, "Ins, Del : create/delete box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 120 }, "O, P : prev/next box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 140 }, "WASD : move box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 160 }, "Q, E : enlarge/shrink box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 180 }, "ENTER : save data", olc::WHITE);

		//debug
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 220 }, "current animation: " + GetCurrentSpriteString(), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 240 }, "current animation frame: " + std::to_string(GetCurrentFrame()), olc::YELLOW);
	}

	void MenuController::OnFixedUpdate()
	{

	}

	RB::Sprites::SpriteEnum MenuController::GetCurrentSpriteEnum()
	{
		RB::Players::iPlayer* player = _getter_PlayerController.GetController()->GetPlayerOnIndex(0);
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(player->GetPlayerID());

		if (state == nullptr)
		{
			return _currentSpriteEnum;
		}

		state->GetSpriteEnum();
		_currentSpriteEnum = state->GetSpriteEnum();

		return _currentSpriteEnum;
	}

	const std::string& MenuController::GetCurrentSpriteString()
	{
		RB::Sprites::SpriteEnum se = GetCurrentSpriteEnum();

		const std::string& str = _getter_SprDataController.GetController()->GetString(se);

		return str;
	}

	int32_t MenuController::GetCurrentFrame()
	{
		RB::Render::PlayerAnimationObj* obj = _getter_pAniController.GetController()->GetAnimationObj(RB::Players::PlayerID::PLAYER_1, _currentSpriteEnum);

		if (obj == nullptr)
		{
			return 0;
		}

		return obj->GetCurrentIndex();
	}
}