#pragma once

#include "Position.h"
#include "Point.h"

typedef struct {
	PPosition p;
}Robot;


typedef Robot* PRobot;

PRobot createRobot();
bool setLocation(PRobot r, double x, double y, double angle);
PPoint whereIsRob(PRobot);

/*bool canMove();*/
