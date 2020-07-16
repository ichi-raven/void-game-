#pragma once

#include <functional>
#include <cstdint>

enum class EventType
{
	eOnce,
	eRepeat,
};

class Event
{
public:

	Event()
		: mTriggerTime(0)
		, mStartFunc([](Event*) {})
		, mUpdateFunc([](Event*) {})
		, mEndFunc([](Event*) {})
		, mElapsedFrame(0)
		, mType(EventType::eOnce)
		, mEndFlag(false)
	{

	}

	Event
	(
		const double triggerTime,
		EventType type,
		const std::function<void(Event * pE)>& startFunc,
		const std::function<void(Event * pE)>& updateFunc,
		const std::function<void(Event * pE)>& endFunc
	);

	void setTriggerTime(const double& triggerTime);

	double getTriggerTime() const;

	void setStartFunc(const std::function<void(Event* pE)>& startFunc);

	void executeStartFunc();

	void setUpdateFunc(const std::function<void(Event* pE)>& updateFunc);

	void executeUpdateFunc();

	void setEndFunc(const std::function<void(Event* pE)>& endFunc);

	void executeEndFunc();

	void setEndFlag();

	bool getEndFlag() const;

	void setType(EventType type);

	EventType getType() const;

	uint64_t getElapsedFrame() const;


private:
	double							mTriggerTime;
	uint64_t						mElapsedFrame;
	std::function<void(Event* pE)>	mStartFunc;
	std::function<void(Event* pE)>	mUpdateFunc;
	std::function<void(Event* pE)>	mEndFunc;
	EventType						mType;
	bool							mEndFlag;
};