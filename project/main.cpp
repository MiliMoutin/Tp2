#include<iostream>
#include <allegro5/allegro.h> 
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_audio.h> // NO OLVIDAR AGREGAR EN EL LINKER DEL PROYECTO
#include <allegro5/allegro_acodec.h> // NO OLVIDAR AGREGAR EN EL LINKER DEL PROYECTO
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <stdbool.h>

#include "tp2_allegro.h"
#include "Floor.h"
#include "Point.h"
#include "Position.h"
#include "Robot.h"

using namespace std;

#define FILAS 10
#define COLUMNAS 20





int main(int argc, char **argv)
{
	allegro_t allegro_data;						//Estructura para allegro
	allegro_t * allegro_p = &allegro_data;


	if (init_allegro(allegro_p)) //Inicializo allegro
	{
		return 0; //si fallas devuelve 0
	}



	float size_floor_h = SCREEN_H / COLUMNAS;
	float size_floor_w = SCREEN_W / FILAS;
	float size_floor = size_floor_h > size_floor_w ? size_floor_h : size_floor_w;   //Determino tamaño de baldosa para que se ajuste a la ventana
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

	Select_mode(FILAS, COLUMNAS, allegro_p);   //Select Mode devuelve un int indicando el modo 1 o 2
	

	
	al_flip_display(); // actualizo display


	al_destroy_display(allegro_data.display); //destruyo display display

	return 0;
}

