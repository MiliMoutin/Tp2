#include <iostream>
#include <cmath>
#include "Position.h"



using namespace std;

PPosition createPos(double x, double y, double angle) {
	PPosition toret = (PPosition) malloc(sizeof(Position));
	if (toret == NULL) {
		free(toret);
		return NULL;
	}
	toret->x = x;
	toret->y = y;
	toret->angle = angle;
	return toret;
}


bool setCoordinates(PPosition po, double x, double y, double angle) {
	po->x = x;
	po->y = y;
	po->angle = angle;
	return true;
}

/*
bool movePoint(PPosition po, double delta, double angle) {
	return setCoordinates(po, cos((180 / 3.1415)*angle)*delta, sin((180 / 3.1415)*angle)*delta, angle);
}
*/
double wherex(PPosition po) {
	return po->x;
}

double wherey(PPosition po) {
	return po->y;
}

double angle(PPosition po) {
	return po->angle;
}

bool nextCoordinate(PPosition po,double xmax, double ymax) // recibe el punto y el maximo valor que pueden tener las coordenadas en el piso creado
{
	double x = wherex(po);
	double y = wherey(po);
	double angulo = angle(po);


	x = x + cos((angulo / 180)*M_PI);
	y = y + sin((angulo / 180)*M_PI);

	if (((x > xmax) || (x < 0)) || ((y > ymax) || (y < 0))) //verfica que la nueva posicion no se salga del mapa
	{
		angulo = rand() % MAX_DEGREE_ROTATION; //cambia el angulo
		return false;
	}
	else
	{
		setCoordinates(po, x, y, angulo); //guarda nueva posicion
		return true;
	}

	
}