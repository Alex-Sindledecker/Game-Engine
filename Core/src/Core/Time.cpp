#include "pch.h"
#include "Time.h"
#include "StringTools.h"

namespace Engine
{

	Clock Clock::mGlobalClock;

	Clock::Clock()
	{
		mStart = std::chrono::high_resolution_clock::now();
	}

	double Clock::tick()
	{
		auto current = std::chrono::high_resolution_clock::now();
		double elapsed = std::chrono::duration<double>(current - mLastTick).count();
		mLastTick = current;

		return elapsed;
	}

	double Clock::now()
	{
		return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - mStart).count();
	}

	std::string Clock::nowAsMSM()
	{
		auto elapsed = std::chrono::high_resolution_clock::now() - mStart;
		int min = std::chrono::duration_cast<Minutes>(elapsed).count();
		int sec = std::chrono::duration_cast<Seconds>(elapsed).count();
		int mil = std::chrono::duration_cast<Milliseconds>(elapsed).count();

		return buildFormattedString("[{}:{}:{}]", min, sec % 60, mil % 1000);
	}

	void Clock::restart()
	{
		mStart = std::chrono::high_resolution_clock::now();
	}

	double Clock::getGlobalTime()
	{
		return mGlobalClock.now();
	}

	std::string Clock::getGlobalTimeAsMSM()
	{
		return mGlobalClock.nowAsMSM();
	}

	Timer::Timer()
	{
	}

	void Timer::start()
	{
		mStart = std::chrono::high_resolution_clock::now();
	}

	double Timer::stop()
	{
		return std::chrono::duration_cast<Microseconds>(std::chrono::high_resolution_clock::now() - mStart).count() / 1000.0;
	}

}