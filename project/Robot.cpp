

#include "Robot.h"


using namespace std;

PRobot createRobot() {
	PRobot toret = (PRobot)malloc(sizeof(Robot));
	if (toret == NULL) {
		free(toret);
		return NULL;
	}
	toret->p = createPos(-1, -1, -1);
	return toret;
}

bool setLocation(PRobot r, double x, double y, double angle) {
	setCoordinates(r->p, x, y, angle);
	return true;
}

double whereIsRobX(PRobot r) {
	return wherex(r->p);
}
double whereIsRobY(PRobot r) {
	return wherey(r->p);
}
double angleRob(PRobot r) {
	return angle(r->p);
}
/*no se si va a ser necesario aun*/
/*PPoint newLocation(PRobot, double delta, double angle) 
{
	
	return 
}*/



PRobot createRobots(Sim_t * Sim_p)
{
	PRobot bots = NULL;		//defino 
	bots = (PRobot)malloc(sizeof(PRobot)*(Sim_p->nRobot);	//reservo espacio pa robots
	if (bots != NULL)
	{
		srand(time(NULL));		
		for (int i = 0; i < (Sim_p->nRobot); i++)
		{	
			setLocation(bots +i, rand() % Sim_p->floor.m, rand() % Sim_p->floor.n, rand() % MAX_DEGREE_ROTATION); // va creando los robots
		}
	}
	return bots;
}

int movement(Robot_t* robots, int cant_Robots, Piso_t*piso, int tick_counter)
{

	for (int i = 0; i < cant_Robots; i++)	//mueve cada robot
	{
		(robots + i)->move(piso->ancho, piso->largo);
	}
	tick_counter++;		//y aumenta el contador de ticks

	return tick_counter;		//Devuelve contador de ticks
}