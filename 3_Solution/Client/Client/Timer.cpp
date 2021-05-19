#include "Timer.h"

Timer::Timer(eTimer active) :m_expirationTime(0.0f), m_elapsedTime(0.0f),
m_active(static_cast<bool>(active))
{
}

Timer::Timer(float _expirationTime, eTimer active) : m_expirationTime(_expirationTime),
m_elapsedTime(0.0f), m_active(static_cast<bool>(active))
{
}

float Timer::getExpirationTime() const
{
	return m_expirationTime;
}

bool Timer::isExpired() const
{
	if (m_active)
	{
		return m_elapsedTime > m_expirationTime;
	}
	else
	{
		return false;
	}
}

void Timer::setExpiredTime(float expirationTime)
{
	m_elapsedTime = 0.0f;
	m_expirationTime = expirationTime;
}

void Timer::setActive(bool active)
{
	m_active = active;
}

void Timer::resetElapsedTime()
{
	m_elapsedTime = 0.0f;
}

void Timer::update(float deltaTime)
{
	if (m_active)
	{
		m_elapsedTime += deltaTime;
	}
}
