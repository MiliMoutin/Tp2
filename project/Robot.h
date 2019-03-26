#pragma once



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

PRobot createRobots(Sim_t * Sim_p);
void move(PRobot robots, Sim_t* Sim_p);
/*bool canMove();*/
