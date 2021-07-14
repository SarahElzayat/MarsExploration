#include "PromoteEvent.h"
#include"..\MarsStation\MarsStation.h"

PromoteEvent::PromoteEvent(MarsStation* MS, int day, int ID) : Event(day, ID, MS)
{
}

void PromoteEvent::Execute()
{
	Station->PromoteMission(this->getMissionID()); //Promate a Mountainous Mission by ID to Emergency
}

PromoteEvent::~PromoteEvent()
{
}
