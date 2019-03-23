#pragma once

typedef struct {
	double x;
	double y;
}Point;


typedef Point* PPoint;

PPoint createPoint(double y, double x);
bool setCoordinatesPoint(PPoint p, double x, double y);
double x(PPoint p);
double y(PPoint p);
