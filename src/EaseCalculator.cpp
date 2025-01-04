#include "EaseCalculator.h"

namespace RB
{
    void EaseCalculator::Init()
    {

    }

    void EaseCalculator::OnUpdate()
    {

    }

    void EaseCalculator::OnFixedUpdate()
    {
        float progress = (float)_currentFixedUpdateCount / (float)_totalFixedUpdateCount;
        float eased = 0.0f;

        if (_easeType == EaseType::EaseOutSine)
        {
            eased  = Ease::EaseOutSine(progress);
        }
        else if (_easeType == EaseType::EaseInSine)
        {
            eased  = Ease::EaseInSine(progress);
        }
        else
        {
            return;
        }

        if (eased >= 1.0f)
        {
            eased = 1.0f;
        }
        else if (eased <= 0.0f)
        {
            eased = 0.0f;
        }

        _currentPercentage = _startingPercentage + (eased * (_targetPercentage - _startingPercentage));

        _currentFixedUpdateCount++;
    }

    void EaseCalculator::SetTarget(int totalFixedUpdateCount, EaseType easeType, float startingPercentage, float targetPercentage)
    {
        //_currentPercentage = 0.0f;
        _currentFixedUpdateCount = 0;

        _startingPercentage = startingPercentage;
        _targetPercentage = targetPercentage;
        _totalFixedUpdateCount = totalFixedUpdateCount;
        _easeType = easeType;
    }

    float EaseCalculator::GetCurrentPercentage()
    {
        return _currentPercentage;
    }
}