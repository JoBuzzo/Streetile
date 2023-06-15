#include<allegro5/allegro5.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include<iostream>
#include<conio.h>

#define BLOCKSIZE 32
#define WMAPA 40
#define HMAPA 25
#define SCREENWIDTH BLOCKSIZE*WMAPA
#define SCREENHEIGHT BLOCKSIZE*25

int mapa[HMAPA][WMAPA] = {

    { 6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6 },//checkpoint

    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//calçada
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
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//calçada
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//calçada
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
#include"IceCreamTruck.h"
#include"DodgeRAM.h"
#include"Mapa.h"

void DrawMap() {
    for (int i = 0; i < HMAPA; i++) {
        for (int j = 0; j < WMAPA; j++) {
            al_draw_bitmap(blocos[mapa[i][j]], j * BLOCKSIZE, i * BLOCKSIZE, 0);
        }
    }
}

bool reScreen(Galinha galinha) {

    int dx = galinha.posX / BLOCKSIZE;
    int dy = galinha.posY / BLOCKSIZE;
    int dx1 = (galinha.posX + 32) / BLOCKSIZE;
    int dy1 = (galinha.posY + 32) / BLOCKSIZE;

    if (mapa[dy][dx] == 6) {


        return true;
    }
    else if (mapa[dy][dx1] == 6) {

        return true;
    }
    else if (mapa[dy1][dx] == 6) {

        return true;
    }
    else if (mapa[dy1][dx1] == 6) {

        return true;
    }
    return false;
}

bool toggleFullScreen(ALLEGRO_DISPLAY*& display, bool isFullScreen) {
     isFullScreen = !isFullScreen;

    int windowFlags = al_get_display_flags(display);
    bool isAlreadyFullScreen = (windowFlags & ALLEGRO_FULLSCREEN) != 0;

    al_destroy_display(display);


    if (isFullScreen && !isAlreadyFullScreen) {
        al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    }
    else if (!isFullScreen && isAlreadyFullScreen) {
        al_set_new_display_flags(ALLEGRO_WINDOWED);
    }


   display = al_create_display(SCREENWIDTH, SCREENHEIGHT);
   al_set_window_title(display, "atravesse a rua!");
   al_set_window_position(display, 0, 0);


    return isFullScreen;
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
    al_set_window_position(display, 0, 0);

    bool isFullScreen = false;


    blocos[0] = al_load_bitmap("tiles/rua.png");
    blocos[1] = al_load_bitmap("tiles/rua_tartaruga.png");
    blocos[2] = al_load_bitmap("tiles/calcada_lado_rua_baixo.png");
    blocos[3] = al_load_bitmap("tiles/calcada_lado_rua_cima.png");
    blocos[4] = al_load_bitmap("tiles/calcada_meio.png");
    blocos[5] = al_load_bitmap("tiles/rua_divisa.png");
    blocos[6] = al_load_bitmap("tiles/calcada_meio.png");


    Galinha galinha;

    Fusca fusca;
    fusca.setPosY(17);
    fusca.setPosX(40);

    Perua perua;
    perua.setPosY(17);
    perua.setPosX(15);


    Fusca fusca1;
    fusca1.setPosY(14);
    fusca1.setSpeed(4);
    fusca1.setPosX(34);

    Van van;
    van.setPosY(14);
    van.setSpeed(4);

    Mustang mustang1(true);
    mustang1.setPosY(14);
    mustang1.setPosX(28);


    FocusRS focus;
    focus.setDirection();
    focus.setPosY(11);

    DodgeRAM dodge;
    dodge.setDirection();
    dodge.setPosY(11);
    dodge.setPosX(5);

    Mustang mustang;
    mustang.setDirection();
    mustang.setPosY(11);
    mustang.setPosX(20);


    Cadillac cadillac;
    cadillac.setDirection();
    cadillac.setPosY(8);

    IceCreamTruck truck;
    truck.setDirection();
    truck.setPosY(7);
    truck.setPosX(20);



    ALLEGRO_TIMER* timer = al_create_timer(1.0/90.0);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
 
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
        else if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
            int keycode = events.keyboard.keycode;
            galinha.keyDOWN(keycode);

            if (events.keyboard.keycode == ALLEGRO_KEY_F11) {
                isFullScreen = toggleFullScreen(display, isFullScreen);
                if (!isFullScreen) {
                    al_register_event_source(event_queue, al_get_display_event_source(display));
                }

                fusca.reloadBitMap();
                fusca1.reloadBitMap();
                perua.reloadBitMap();
                van.reloadBitMap();
                focus.reloadBitMap();
                cadillac.reloadBitMap();
                mustang.reloadBitMap();
                truck.reloadBitMap();
                mustang1.reloadBitMap();
                dodge.reloadBitMap();
                galinha.reloadBitMap();
                
                blocos[0] = al_load_bitmap("tiles/rua.png");
                blocos[1] = al_load_bitmap("tiles/rua_tartaruga.png");
                blocos[2] = al_load_bitmap("tiles/calcada_lado_rua_baixo.png");
                blocos[3] = al_load_bitmap("tiles/calcada_lado_rua_cima.png");
                blocos[4] = al_load_bitmap("tiles/calcada_meio.png");
                blocos[5] = al_load_bitmap("tiles/rua_divisa.png");
                blocos[6] = al_load_bitmap("tiles/calcada_meio.png");
            }

        }
        else {
            if (events.type == ALLEGRO_EVENT_KEY_UP) {
                int keycode = events.keyboard.keycode;
                galinha.keyUP(keycode);
            }
            
        }

         galinha.move();
        

        if (!reScreen(galinha)) {
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
            truck.move();
            truck.collide(galinha);
            mustang1.move();
            mustang1.collide(galinha);
            dodge.move();
            dodge.collide(galinha);
        }
        else {
            fusca.active = false;
            fusca1.active = false;
            perua.active = false;
            van.active = false;
            focus.active = false;
            cadillac.active = false;
            mustang.active = false;
            truck.active = false;
            mustang1.active = false;
            dodge.active = false;
        }


        if (redraw && al_is_event_queue_empty(event_queue)) {
            DrawMap();
            galinha.draw();
            fusca.draw();
            fusca1.draw();
            perua.draw();
            van.draw();
            focus.draw();
            cadillac.draw();
            mustang.draw();
            truck.draw();
            mustang1.draw();
            dodge.draw();

            galinha.drawHeart();
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
    truck.destroy();
    mustang1.destroy();
    dodge.destroy();

    al_destroy_display(display);


}