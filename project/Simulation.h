#pragma once


#include "Robot.h"
#include "Floor.h"
#include "tp2_allegro.h"

typedef struct
{
	PRobot robot;
	int	nRobot;
	Floor floor;
	int Mode;
	int TickCount;
	int state; //limpio o sucio
}Sim_t;

int CreateSimulation(Sim_t*,allegro_t *);
bool DestroySimulation(void);