#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iController.h"
#include "iDebugRenderer.h"

namespace RB::Render
{
	class iBoxRenderController : public RB::Controllers::iController
	{
	public:
		virtual ~iBoxRenderController() {}

	public:
		virtual iDebugRenderer* GetBoxRenderer() = 0;
	};
}