/* 
--- Control de Allegro
*/


#include "tp2_allegro.h"

using namespace std;




void Colocate_grid(int col, int fil, float size_floor);



bool init_allegro(allegro_t * allegro_p)
{
	
	allegro_p->display = NULL;           //Puntero a display
	allegro_p->event_queue = NULL;   //Puntero a cola de eventos
	allegro_p->timer = NULL;                //puntero a timer
	allegro_p->cleaner_robot = NULL;        //Puntero a imagen

	

	if (!al_init())  //Inicializo allegro
	{ //Primera funcion a llamar antes de empezar a usar allegro.
		fprintf(stderr, "failed to initialize allegro!\n");
		return 1;
	}



	allegro_p->timer = al_create_timer(1.0 / FPS); //timer para actualizacion de pantalla
	if (!allegro_p->timer)
	{
		fprintf(stderr, "failed to create timer!\n");
		return 1;
	}


	if (!al_init_image_addon())
	{   // ADDON necesario para manejo(no olvidar el freno de mano) de imagenes 
		fprintf(stderr, "failed to initialize image addon !\n");
		al_destroy_timer(allegro_p->timer);
		return 1;
	}

	if (!al_init_primitives_addon())
	{   // ADDON necesario para manejo(no olvidar el freno de mano) de imagenes 
		fprintf(stderr, "failed to initialize image addon !\n");
		al_destroy_timer(allegro_p->timer);
		return 1;
	}

	if (!al_install_keyboard()) //Inicializo teclado
	{
		fprintf(stderr, "failed to initialize the keyboard!\n");
		al_destroy_timer(allegro_p->timer);
		return 1;
	}



	//Inicializo puntero de imagenes a imagenes correspondientes
	allegro_p->cleaner_robot = al_load_bitmap("robot_cleaner.png"); //Led apagado

	if (!allegro_p->cleaner_robot) //pregunto si imagen se inicializo correctamente
	{
		fprintf(stderr, "failed to load image !\n");
		al_destroy_timer(allegro_p->timer);
		return 1;
	}





	allegro_p->display = al_create_display(SCREEN_W, SCREEN_H); // Inicializo display 800*600
	if (!allegro_p->display)  //pregunto si display se inicializo correctamente
	{
		al_destroy_bitmap(allegro_p->cleaner_robot); //Si falla cierro todo lo que se inicializo
		al_destroy_timer(allegro_p->timer);
		fprintf(stderr, "failed to create display!\n");
		return 1;
	}


	allegro_p->event_queue = al_create_event_queue(); // inicializo cola de eventos

	/*display en negro------------------------*/
	al_clear_to_color(al_map_rgb(0, 0, 0)); //Hace clear del backbuffer del diplay al color RGB 0,0,0 (negro)

	if (!allegro_p->event_queue)  //pregunto si cola de eventos se inicializo correctamente
	{
		al_destroy_bitmap(allegro_p->cleaner_robot); //Si falla cierro todo lo que se inicializo
		al_destroy_display(allegro_p->display);
		al_destroy_timer(allegro_p->timer);
		fprintf(stderr, "failed to create event_queue!\n");
		return 1;
	}

	al_register_event_source(allegro_p->event_queue, al_get_display_event_source(allegro_p->display));
	al_register_event_source(allegro_p->event_queue, al_get_timer_event_source(allegro_p->timer)); //registro timer
	al_register_event_source(allegro_p->event_queue, al_get_keyboard_event_source()); //REGISTRAMOS EL TECLADO

	
	return 0;
}


void Create_dirty_floor(int col,int fil,float size_floor)
{

	al_draw_filled_rectangle(0,0, size_floor*col, size_floor*fil, al_map_rgb(50, 50, 50));
	Colocate_grid(col, fil, size_floor);
	
	return;
}

void Clean_floor(int x, int y,float size_floor)
{
	al_draw_filled_rectangle(size_floor*x+ THICKNESS_LINE, size_floor*y+ THICKNESS_LINE, size_floor*(x + 1)- THICKNESS_LINE, size_floor*(y + 1)- THICKNESS_LINE, al_map_rgb(255,255,255));

	return;
}

void Colocate_grid(int col, int fil,float size_floor)
{
	for (int i = 1; i < fil; i++)
			al_draw_line(0, size_floor*i, size_floor*col, size_floor*i, al_map_rgb(0, 0, 0), THICKNESS_LINE);

	for (int i = 1; i < fil; i++)
		al_draw_line(size_floor*i, 0, size_floor*i, size_floor*fil, al_map_rgb(0, 0, 0), THICKNESS_LINE);
}

void Set_robot(float x, float y,float angle, allegro_t * allegro_p,float size_floor)
{

	al_draw_scaled_rotated_bitmap(allegro_p->cleaner_robot,x*size_floor, y*size_floor, x*size_floor, y*size_floor, 0.0005*size_floor, 0.0005*size_floor,angle, 0);

	return;

}