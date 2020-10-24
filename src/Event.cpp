#include "Event.hpp"
#include "EventBehav.hpp"

#include <Siv3D.hpp>

// Event::Event(const double &triggerTime, const EventBehav *const pBehav)
// {
// 	mTriggerTime = triggerTime;
// 	mElapsedTime = 0;
// 	mEndFlag = false;
// 	mBehav = std::unique_ptr<EventBehav>(pBehav);
// }

Event::~Event()
{
	//if(mBehav)
	//	delete mBehav;
}

void Event::setTriggerTime(const double& triggerTime)
{
	mTriggerTime = triggerTime;
}

const double& Event::getTriggerTime() const
{
	return mTriggerTime;
}

void Event::setBehav(Enemy &enemy, MyShip &myShip, const Vec2& windowSize, std::shared_ptr<EventBehav> pBehav)//Behavオブジェクトは動的に生成すること
{
	if (!pBehav)
		return;
	if (mBehav)
		mBehav.reset();

	mBehav = pBehav;
	mBehav->init(enemy, myShip, windowSize);
}

void Event::update(Enemy &enemy, MyShip &myShip, const double &elapsedTime)
{
	if(!mBehav)
		return;
	mBehav->update(enemy, myShip, elapsedTime);

	mEndFlag = mBehav->end();
}

void Event::draw() const
{
	if (!mBehav)
		return;
	mBehav->draw();
}

bool Event::checkHit(MyShip& myShip)
{
	if (!mBehav)
		return false;
	return mBehav->checkHit(myShip);
}

bool Event::isEnded() const
{
	return mBehav->end();
}