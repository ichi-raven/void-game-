#pragma once

//#include <functional>
#include <cstdint>
#include <memory>
#include <Siv3D.hpp>


class Object;
class EventBehav;
class Enemy;
class MyShip;

class Event
{
public:
	Event()
		: mTriggerTime(0)
		, mElapsedTime(0)
		, mEndFlag(false)
		, mBehav(nullptr)
	{}

	~Event();

	//Event(const double& triggerTime, const EventBehav* const pBehav);

	void setTriggerTime(const double &triggerTime);

	const double& getTriggerTime() const;

	void setBehav(Enemy& enemy, MyShip& myship, const Vec2& windowSize, std::shared_ptr<EventBehav> pBehav = nullptr);

	void update(Enemy& enemy, MyShip& myship, const double& elapsedTime);

	void draw() const;

	bool checkHit(MyShip& myShip);

	bool isEnded() const;

private:
	double mTriggerTime;
	double mElapsedTime;
	bool mEndFlag;
	std::shared_ptr<EventBehav> mBehav;
};

