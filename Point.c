#include <iostream>;
#include "Point.h";

typedef struct {
	double x;
	double y;
}Point;

PPoint createPoint(double y, double x) {
	PPoint toret = (PPoint*)malloc(sizeof(Point));
	if (toret == NULL) {
		free(toret);
		return NULL;
	}
	toret->y = y;
	toret->x = x;
	return toret;
}

bool setCoordinatesPoint(PPoint p, double x, double y) {
	p->x = x;
	p->y = y;
	return true;
}

double x(PPoint p) {
	return p->x;
}

double y(PPoint p) {
	return p->y;
}