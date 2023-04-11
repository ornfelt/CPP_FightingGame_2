#include "BoxRenderer.h"

namespace RB::Render
{
	BoxRenderer::BoxRenderer()
	{
		std::cout << "constructing BoxRenderer" << std::endl;
	}

	BoxRenderer::~BoxRenderer()
	{
		std::cout << "destroying BoxRenderer" << std::endl;
	}

	void BoxRenderer::Init()
	{
		_spriteLoader.LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteID::x_white);
	}

	void BoxRenderer::RenderSprite(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel color, RB::Sprites::PivotType pivotType)
	{
		RB::Sprites::LoadedSprite* loadedSprite = _spriteLoader.GetLoadedSprite(RB::Sprites::SpriteID::x_white);

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
				olc::vf2d{ pos.x - half.x, 0.0f },
				olc::vf2d{ pos.x + half.x, 0.0f },
				olc::vf2d{ pos.x + half.x, pos.y - widthHeight.y },
			};
		}

		if (RB::Cam::CurrentCam::CamExists())
		{
			for (int i = 0; i < points.size(); i++)
			{
				points[i] = RB::Cam::CurrentCam::GetRelativePos(points[i]);
			}
		}

		olc::Decal* decal = loadedSprite->GetDecal();

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(decal, points, { 0, 0 }, { 50, 50 }, color);
	}
}