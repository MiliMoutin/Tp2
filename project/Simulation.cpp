#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Simulation.h"
#include "tp2_allegro.h"
#include "Floor.h"
#include "Position.h"
#include "Robot.h"

#define MAX_DEGREE_ROTATION 360

void Simulate(Sim_t *, allegro_t *);


int CreateSimulation(Sim_t * Sim_p, allegro_t * allegro_p)
{
	srand(time(NULL));


	if (Sim_p->Mode == 1)
	{
		Simulate(Sim_p,allegro_p);
	}
	else if (Sim_p->Mode == 2)
	{

	}


	return Sim_p->TickCount;
}


void Simulate(Sim_t * Sim_p,allegro_t * allegro_p)
{
	int cantRobot = Sim_p->nRobot;

	float size_floor_h = SCREEN_H / Sim_p->floor.m;
	float size_floor_w = SCREEN_W / Sim_p->floor.n;
	float size_floor = size_floor_h > size_floor_w ? size_floor_w : size_floor_h;   //Determino tamaño de baldosa para que se ajuste a la ventana

	Create_dirty_floor(Sim_p->floor.n,Sim_p->floor.m, size_floor);  //inicio ventana con piso sucio

	al_flip_display(); //actualizo display
	al_rest(2.0); //delay 2 segundos;


	PFloor MyFloor = createFloor(Sim_p->floor.m, Sim_p->floor.n); 

	PRobot MyRobot = createRobot();
	if (MyRobot == NULL)
	{
		return;
	}

	setLocation(MyRobot, rand() % Sim_p->floor.m, rand() % Sim_p->floor.n , rand() % MAX_DEGREE_ROTATION);
	clean(MyFloor, MyRobot->p);			//true posicion de baldosa
	Clean_floor((int)whereIsRobX(MyRobot), (int)whereIsRobY(MyRobot), size_floor);	//pone baldosa en blanco en allegro
	Set_robot(floor(whereIsRobX(MyRobot)),floor( whereIsRobY(MyRobot)), angleRob(MyRobot), allegro_p, size_floor); //coloca robot en allegro;



	al_flip_display();	//actualiza display
	al_rest(5.0);		//delay 5seg






	return;
}





/*
	Create_dirty_floor(FILAS,COLUMNAS,size_floor);  //ejemplo iniciar piso sucio en ventana

	Clean_floor(2,1,size_floor); //ejemplos limpiar baldosa en ventana
	Clean_floor(2,3, size_floor);
	Clean_floor(5,3, size_floor);
	Clean_floor(0,5, size_floor);
	Clean_floor(1,4, size_floor);

	Set_robot(2.5, 1.5, 45, allegro_p,size_floor); //ejemplo colocar robot en ventana
	Set_robot(4, 6.5, 5, allegro_p, size_floor);
	Set_robot(8, 1.5, 60, allegro_p, size_floor);
	*/