#pragma once

#include <string>

#include "iHurtBoxDataController.h"
#include "Loaded_HB_Data.h"
#include "HB_Loader.h"
#include "SpriteType.h"


namespace RB::HBox
{
	class TargetBoxDataController : public iHurtBoxDataController
	{
	public:
		TargetBoxDataController(std::string dir);
		~TargetBoxDataController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		Loaded_HB_Data* GetData(RB::Sprites::SpriteType spriteType) override;
		const std::string& GetPath(RB::Sprites::SpriteType spriteType) const override;

	private:
		HB_Loader _hbLoader;
	};
}