#include "Position.h"
#include "Robot.h"
#include <iostream>

typedef struct {
	PPosition p;
}Robot;


PRobot createRobot() {
	PRobot toret = (PRobot)malloc(sizeof(Robot));
	if (toret == NULL) {
		free(toret);
		return NULL;
	}
	return toret;
}

bool setLocation(PRobot r, double x, double y, double angle) {
	setCoordinates(r->p, x, y, angle);
	return true;
}

PPoint whereIsRob(PRobot r) {
	return where(r->p);
}
/*no se si va a ser necesario aun*/
/*PPoint newLocation(PRobot, double delta, double angle) {
	return 
}*/
