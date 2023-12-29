#include "Sprites.h"

namespace RB::Render
{
	void Sprites::LoadSprite(std::string path, RB::Sprites::SpriteEnum spriteEnum)
	{
		_loader.LoadSprite(path, spriteEnum);
	}

	void Sprites::RenderSprite(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType, bool useWorldSpace)
	{
		if (RB::Cam::iCamController::instance == nullptr)
		{
			return;
		}

		RB::Sprites::LoadedSprite* loadedSprite = _loader.GetLoadedSprite(spriteEnum);

		olc::vf2d half = widthHeight * 0.5f;

		std::array<olc::vf2d, 4> points;

		if (pivotType == RB::Sprites::PivotType::CENTER)
		{
			points = {
				olc::vf2d{ pos.x - half.x, pos.y - half.y },
				olc::vf2d{ pos.x - half.x, pos.y + half.y },
				olc::vf2d{ pos.x + half.x, pos.y + half.y },
				olc::vf2d{ pos.x + half.x, pos.y - half.y },
			};
		}
		else if (pivotType == RB::Sprites::PivotType::BOTTOM_CENTER)
		{
			points = {
				olc::vf2d{ pos.x - half.x, pos.y - widthHeight.y },
				olc::vf2d{ pos.x - half.x, pos.y },
				olc::vf2d{ pos.x + half.x, pos.y },
				olc::vf2d{ pos.x + half.x, pos.y - widthHeight.y },
			};
		}
		else if (pivotType == RB::Sprites::PivotType::BOTTOM_LEFT)
		{
            points = {
				olc::vf2d{ pos.x, pos.y - widthHeight.y },
				olc::vf2d{ pos.x, pos.y },
				olc::vf2d{ pos.x + widthHeight.x, pos.y },
				olc::vf2d{ pos.x + widthHeight.x, pos.y - widthHeight.y },
			};
		}
		else if (pivotType == RB::Sprites::PivotType::BOTTOM_RIGHT)
		{
			points = {
				olc::vf2d{ pos.x - widthHeight.x, pos.y - widthHeight.y },
				olc::vf2d{ pos.x - widthHeight.x, pos.y },
				olc::vf2d{ pos.x, pos.y },
				olc::vf2d{ pos.x, pos.y - widthHeight.y },
			};
		}

		if (useWorldSpace)
		{
			for (auto i = points.begin(); i != points.end(); i++)
			{
				*i = RB::Cam::iCamController::instance->GetCamObj()->GetRelativePosition(*i);
			}
		}

		olc::Decal* decal = loadedSprite->GetDecal();
		olc::Sprite* sprite = loadedSprite->GetSprite();

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(decal, points, { 0, 0 }, sprite->Size(), tint);
	}

	RB::Sprites::LoadedSprite* Sprites::GetLoadedSprite(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _loader.GetLoadedSprite(spriteEnum);
	}
}