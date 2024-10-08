#include "RenderTransparencyObj.h"

namespace RB::Render
{
    RenderTransparencyObj::RenderTransparencyObj(int totalFrames, OperationType operationType, float totalTransparency)
    {
        _totalFrames = totalFrames;
        _operationType = operationType;
        _totalAmount = totalTransparency;
    }

    void RenderTransparencyObj::OnFixedUpdate()
    {
        
    }

    void RenderTransparencyObj::SetStart(float start)
    {
      if (_processedFrames == 0)
      {
        _start = start;
    
        //std::cout << std::endl;
        //std::cout << "setting start transparency: " << start  << std::endl;
    
        _end = start * _totalAmount;
    
        //std::cout << "setting end transparency: " << _end << std::endl;
      }
    }
}
