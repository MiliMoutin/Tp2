#pragma once


#include "Robot.h"
#include "Floor.h"

typedef struct
{
	PRobot robot;
	int	nRobot;
	PFloor floor;
	int Mode;
	int TickCount;
	int state; //limpio o sucio
}Sim_t;

int CreateSimulation(Sim_t*);
bool DestroySimulation(void);