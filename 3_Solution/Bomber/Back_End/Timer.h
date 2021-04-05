#pragma once

enum class eTimer
{
	eFalse = 0,
	eTrue
};

class Timer
{
private:
	float m_expirationTime;
	float m_elapsedTime;
	bool m_active;

public:
	Timer(eTimer active = eTimer::eFalse);
	Timer(float _expirationTime, eTimer active = eTimer::eFalse);

	float getExpirationTime() const;
	bool isExpired() const;

	void setExpiredTime(float _expirationTime);
	void setActive(bool _active);
	void resetElapsedTime();
	void update(float _deltaTime);
};

