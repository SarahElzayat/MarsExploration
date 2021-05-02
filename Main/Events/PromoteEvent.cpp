#include "PromoteEvent.h"

PromoteEvent::PromoteEvent(int day, int ID) : Event(day, ID)
{
}

void PromoteEvent::Execute()
{
	Station->PromoteMission(this->getMissionID());
}

PromoteEvent::~PromoteEvent()
{
}
