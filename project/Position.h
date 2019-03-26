#pragma once

#include <math.h>
#define _USE_MATH_DEFINES
#define MAX_DEGREE_ROTATION 360

typedef struct{
	double x;
	double y;
	double angle;
}Position;

typedef Position* PPosition;

PPosition createPos(double x, double y, double angle);
bool setCoordinates(PPosition po, double x, double y, double angle);
//bool movePoint(PPosition po, double delta, double angle);
double wherex(PPosition po);
double wherey(PPosition po);
double angle(PPosition po);
bool nextCoordinate(PPosition po, double angle, double xmax, double ymax);
