#pragma once
#include "Position.h"
#include "Floor.h"
#include "Simulation.h"
#include <time.h>
#include <iostream>
#include <cstdlib>


typedef struct {
	PPosition p;
}Robot;


typedef Robot* PRobot;

PRobot createRobot();
bool setLocation(PRobot r, double x, double y, double angle);
double whereIsRobX(PRobot r);
double whereIsRobY(PRobot r);
double angleRob(PRobot r);

/*bool canMove();*/
