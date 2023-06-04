#include<allegro5/allegro5.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<iostream>

#define BLOCKSIZE 32
#define WMAPA 40
#define HMAPA 50
#define SCREENWIDTH BLOCKSIZE*WMAPA
#define SCREENHEIGHT BLOCKSIZE*25

int mapa[HMAPA][WMAPA] = {
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//cal�ada
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },//sarjeta cima
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//rua
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },//sarjeta baixo
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },//sarjeta cima
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//rua
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },//sarjeta baixo
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//cal�ada
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//cal�ada
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },

    { 6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6 },//checkpoint

    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//cal�ada
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },//sarjeta cima
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//rua
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },//rua
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//rua
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },//sarjeta baixo
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//cal�ada
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//cal�ada
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
};
ALLEGRO_BITMAP* blocos[7] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL};

#include"Galinha.h"
#include"Carro.h"
#include"Fusca.h"
#include"Perua.h"
#include"Van.h"
#include"FocusRS.h"
#include"Cadillac.h"
#include"Mustang.h"

void DrawMap() {
    for (int i = 0; i < HMAPA; i++) {
        for (int j = 0; j < WMAPA; j++) {
            al_draw_bitmap(blocos[mapa[i][j]], j * BLOCKSIZE, i * BLOCKSIZE, 0);
        }
    }
}

bool reScreen(float& tela, Galinha galinha) {

    int dx = galinha.posX / BLOCKSIZE;
    int dy = galinha.posY / BLOCKSIZE;
    int dx1 = (galinha.posX + 32) / BLOCKSIZE;
    int dy1 = (galinha.posY + 32) / BLOCKSIZE;

    if (mapa[dy][dx] == 6) {
        tela += 25 * BLOCKSIZE;
        for (dx = 0; dx < WMAPA; dx++)
            mapa[dy][dx] = 4;
        return true;
    }
    else if (mapa[dy][dx1] == 6) {
        tela += 25 * BLOCKSIZE;
        for (dx = 0; dx < WMAPA; dx++)
            mapa[dy][dx] = 4;
        return true;
    }
    else if (mapa[dy1][dx] == 6) {
        tela += 25 * BLOCKSIZE;
        for (dx = 0; dx < WMAPA; dx++)
            mapa[dy][dx] = 4;
        return true;
    }
    else if (mapa[dy1][dx1] == 6) {
        tela += 25 * BLOCKSIZE;
        for (dx = 0; dx < WMAPA; dx++)
            mapa[dy][dx] = 4;
        return true;
    }
    return false;
}

int main()
{
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();


    ALLEGRO_DISPLAY* display;
    display = al_create_display(SCREENWIDTH, SCREENHEIGHT);
    al_set_window_title(display, "atravesse a rua!");
    al_set_window_position(display, 350, 0);


    blocos[0] = al_load_bitmap("tiles/rua.png");
    blocos[1] = al_load_bitmap("tiles/rua_tartaruga.png");
    blocos[2] = al_load_bitmap("tiles/calcada_lado_rua_baixo.png");
    blocos[3] = al_load_bitmap("tiles/calcada_lado_rua_cima.png");
    blocos[4] = al_load_bitmap("tiles/calcada_meio.png");
    blocos[5] = al_load_bitmap("tiles/rua_divisa.png");
    blocos[6] = al_load_bitmap("tiles/calcada_meio.png");


    Galinha galinha;

    Fusca fusca;

    Fusca fusca1;
    fusca1.posX = 5 * 32;
    fusca1.posY = 38 * 32;
 

    Perua perua;
    perua.posX = BLOCKSIZE * 20;


    Van van;
    van.posY = 38 * 32;

    FocusRS focus;
    focus.setSpeed(-4);
    focus.left = false;
    focus.posY = 35 * 32;
    focus.posX = 40 * 32;


    Cadillac cadillac;
    cadillac.setSpeed(-2);
    cadillac.left = false;
    cadillac.posY = 32 * 32;
    cadillac.posX = 40 * 32;


    Mustang mustang;
    mustang.setSpeed(-3);
    mustang.left = false;
    mustang.posY = 35 * 32;
    mustang.posX = 40 * 32;

    ALLEGRO_TIMER* timer = al_create_timer(1.0/90.0);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    ALLEGRO_TRANSFORM transf;
 
    float dy = SCREENHEIGHT - HMAPA * BLOCKSIZE;

    bool redraw = true;
    al_start_timer(timer);

    while (true) {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);

        if (events.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        }
        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        galinha.move(events);

        al_identity_transform(&transf);
        al_translate_transform(&transf, 0, dy);
        al_use_transform(&transf);

        if (!reScreen(dy, galinha)) {
            fusca.move();
            fusca.collide(galinha);
            fusca1.move();
            fusca1.collide(galinha);
            perua.move();
            perua.collide(galinha);
            van.move();
            van.collide(galinha);
            focus.move();
            focus.collide(galinha);
            cadillac.move();
            cadillac.collide(galinha);
            mustang.move();
            mustang.collide(galinha);
        }
        else {
            fusca.active = false;
            fusca1.active = false;
            perua.active = false;
            van.active = false;
            focus.active = false;
            cadillac.active = false;
            mustang.active = false;
        }


        if (redraw) {
            DrawMap();
            galinha.draw();
            fusca.draw();
            fusca1.draw();
            perua.draw();
            van.draw();
            focus.draw();
            cadillac.draw();
            mustang.draw();

            galinha.drawHeart(dy);
            al_flip_display();
            redraw = false;
        }
    }

    for (int i = 0; i < 6; i++) {
        al_destroy_bitmap(blocos[i]);
    }

    galinha.destroy();
    fusca.destroy();
    fusca1.destroy();
    perua.destroy();
    van.destroy();
    focus.destroy();
    cadillac.destroy();
    mustang.destroy();
    al_destroy_display(display);


}