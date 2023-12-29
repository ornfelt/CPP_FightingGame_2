#pragma once

#include <vector>
#include "_HBoxLoader.h"

namespace RB::HBox
{
	class HB
	{
	public:
		void Init();
		void OnFixedUpdate();

		void SetDir(std::string dir);
		HBox_Layer_1* GetL1(RB::Sprites::SpriteEnum spriteEnum);
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const;

	private:
		_HBoxLoader _loader;
		std::vector<HBox_Layer_1> _vecL1;

		const std::string _none = "none";
		std::string _dir = "HBDirectory/";
		std::string _extention = ".HurtBoxSpecs";
	};
}