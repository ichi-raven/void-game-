#include "Event.hpp"

Event::Event
(
	const double triggerTime,
	EventType type,
	const std::function<void(Event * pE)>& startFunc,
	const std::function<void(Event * pE)>& updateFunc,
	const std::function<void(Event * pE)>& endFunc
)
{
	mTriggerTime = triggerTime;
	mType = type;
	mStartFunc = startFunc;
	mUpdateFunc = updateFunc;
	mEndFunc = endFunc;
	mEndFlag = false;
}

void Event::setTriggerTime(const double& triggerTime)
{
	mTriggerTime = triggerTime;
}

double Event::getTriggerTime() const
{
	return mTriggerTime;
}

void Event::setStartFunc(const std::function<void(Event * pE)>& startFunc)
{
	mStartFunc = startFunc;
}

void Event::executeStartFunc()
{
	mStartFunc(this);
}

void Event::setUpdateFunc(const std::function<void(Event * pE)>& updateFunc)
{
	mUpdateFunc = updateFunc;
}

void Event::executeUpdateFunc()
{
	mUpdateFunc(this);
	++mElapsedFrame;
}

void Event::setEndFunc(const std::function<void(Event * pE)>& endFunc)
{
	mEndFunc = endFunc;
}

void Event::executeEndFunc()
{
	mEndFunc(this);
}


void Event::setType(EventType type)
{
	mType = type;
}

EventType Event::getType() const
{
	return mType;
}

void Event::setEndFlag(bool endFlag)
{
	mEndFlag = endFlag;
}

bool Event::getEndFlag() const
{
	return mEndFlag;
}

uint64_t Event::getElapsedFrame() const
{
	return mElapsedFrame;
}