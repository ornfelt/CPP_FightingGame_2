#include "RenderRotationObj.h"

namespace RB::Render
{
    RenderRotationObj::RenderRotationObj(int totalFrames, float totalRotation)
    {
        _totalFrames = totalFrames;
        _totalRotation = totalRotation;
    }

    float RenderRotationObj::GetRotation()
    {
        return 0.0f;
    }
}
