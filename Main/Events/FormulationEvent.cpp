#include "FormulationEvent.h"
#include"..\MarsStation\MarsStation.h"

FormulationEvent::FormulationEvent(MissionType Type, int day, int ID, int loc, int dur, int sig) : Event(day, ID), MType(Type)
{
	TLOC = loc;
	MDUR = dur;
	SIG = sig;
}

void FormulationEvent::Execute()
{
	if (MType == Emergency)
	{
		EmergencyMission* EM = new EmergencyMission(this->getMissionID(), TLOC, MDUR, SIG, this->getEventDay()); // Create new emergency mission
		Station->AddToEmergencyMissions(EM, EM->GetPriority()); // Add it to the list
		delete EM; // delete
		return;
	}
	else if (MType == Mountainous)
	{
		MountainousMission* MM = new MountainousMission(this->getMissionID(), TLOC, MDUR, SIG, this->getEventDay()); // Create new mountainous mission
		Station->AddToMountainousMissions(MM); // Add it to the list
		delete MM; // delete
		return;
	}
	// Mission type is polar
	PolarMission* PM = new PolarMission(this->getMissionID(), TLOC, MDUR, SIG, this->getEventDay()); // Create new polar mission
	Station->AddToPolarMissions(PM); // Add it to the list
	delete PM; // Deallocation
}

FormulationEvent::~FormulationEvent()
{
}
