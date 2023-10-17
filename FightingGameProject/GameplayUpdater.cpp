#include "GameplayUpdater.h"

namespace RB::Updaters
{
	GameplayUpdater::GameplayUpdater()
	{
		std::cout << std::endl;
		std::cout << "constructing GameplayUpdater" << std::endl;
	}

	GameplayUpdater::~GameplayUpdater()
	{
		std::cout << std::endl;
		std::cout << "destructing GameplayUpdater" << std::endl;

		RB::Controllers::ActiveControllers::OnEnd();
		RB::States::ActiveStateMachines::OnEnd();
	}

	void GameplayUpdater::Init()
	{
		//render background first
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Background::BackgroundController()));

		RB::Players::PlayerController* playerController = new RB::Players::PlayerController();
		playerController->AddPlayer(new RB::Players::Player(), new RB::PlayerStates::P0_Start(), olc::vi2d{-150, 0}, RB::Players::PlayerID::PLAYER_1);
		playerController->AddPlayer(new RB::Players::Player(), new RB::PlayerStates::P0_Start(), olc::vi2d{150, 0}, RB::Players::PlayerID::PLAYER_2);

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(playerController));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Render::PlayerDebugController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Sprites::SpriteDataController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HBox::HurtBoxDataController("HurtBoxSpecs/")));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HBox::HitBoxDataController("HitBoxSpecs/")));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Collisions::AttackRegisterController()));

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Collisions::GeneralHitStopController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Render::VFXAnimationController()));

		RB::Cam::CAM_CONTROLLER->AllowManualControl(false);
	}

	void GameplayUpdater::OnUpdate()
	{
		RB::Controllers::ActiveControllers::UpdateAll();
	}

	void GameplayUpdater::OnFixedUpdate()
	{
		RB::Controllers::ActiveControllers::FixedUpdateAll();
	}
}