#pragma once

namespace RB::Frames
{
	class Time
	{
	public:
		Time() = delete;
		~Time() = delete;

	private:
		static float _deltaTime;
		static float _fixedDeltaTime;

	public:
		static void SetDeltaTime(float delta);
		static void AddFixedDeltaTime();
		static void ClearFixedDeltaTime();
		static float GetDeltaTime();
		static float GetFixedDeltaTime();
	};
}