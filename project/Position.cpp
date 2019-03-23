#include <iostream> 
#include <cmath>
#include "Position.h"


using namespace std;

PPosition createPoint(double y, double x, double angle) {
	PPosition toret = (PPosition)malloc(sizeof(Position));
	if (toret == NULL) {
		free(toret);
		return NULL;
	}
	toret->p=createPoint(y, x);
	return toret;
}


bool setCoordinates(PPosition po, double x, double y, double angle) {
	setCoordinatesPoint(po->p, x,y);
	po->angle = angle;
	return true;
}

bool movePoint(PPosition po, double delta, double angle) {
	setCoordinatesPoint(po->p, cos((180 / 3.1415)*angle)*delta, sin((180 / 3.1415)*angle)*delta);
	po->angle = angle;
	return true;

}

PPoint where(PPosition po) {
	return po->p;
}