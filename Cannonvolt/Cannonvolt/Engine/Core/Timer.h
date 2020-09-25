#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

/*
Allows the game to have a sense of time 
*/


class Timer
{
public:
	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	Timer& operator =(const Timer&) = delete;
	Timer& operator =(Timer&&) = delete;

	Timer();
	~Timer();

	void Start();
	void UpdateFrameTicks();
	float GetDeltaTime() const;
	unsigned int GetSleepTime(unsigned int fps_) const;
	float GetCurrentTicks();

private:
	unsigned int prevTicks, currentTicks;


};

#endif // !TIMER_H
