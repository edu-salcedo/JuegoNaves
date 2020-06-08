#include <allegro.h>
BITMAP* lienzo;                  // el bitmap lienzo es el fondon base donde se va a imprimir las otras imagenes
#include <iostream>
using namespace std;
# include <list>
#include <math.h>
#include "alarma.h"
#include "bala.h"
#include "nave.h"
#include"enemigos.h"
void init();
void deinit();

int main()
{
    init();
    lienzo = create_bitmap(SCREEN_W,SCREEN_H);
    Nave *nave = new Nave();
    Enemigo *enemi =new Enemigo(-80,15,1);              // el 1 es el movimiento de la nave enemiga
    BITMAP* fondo =load_bitmap("imagen/fondo1.bmp",NULL);
      while (!key[KEY_ESC])
      {
          draw_sprite(lienzo,fondo,0,0); // pinta la imagen del fondo sobre el lienzo
           nave->mover();
           enemi->accion();
           enemi->mover_enemigo();
          draw_sprite(screen,lienzo,0,0);
          clear_to_color(lienzo,0x3F36C5);
      }
    deinit();

    return 0;
}
END_OF_MAIN()


void init() {                             //funcion para iniciar  allegro
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 700, 500, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();

}
void deinit() {
	clear_keybuf();

}
