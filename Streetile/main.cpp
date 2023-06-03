#include<allegro5/allegro5.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#define BLOCKSIZE 32
#define WMAPA 40
#define HMAPA 50
#define SCREENWIDTH BLOCKSIZE*WMAPA
#define SCREENHEIGHT BLOCKSIZE*25

#include"Carro.h"
#include"Fusca.h"

enum KEYS { W, S, A, D };

int mapa[HMAPA][WMAPA] = {
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//calçada
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
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//calçada
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },//calçada
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },

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
    { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
};
ALLEGRO_BITMAP* blocos[7] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL};

bool colideBorda(int &posX, int &posY) {
    if (posX > WMAPA * BLOCKSIZE - 32) {
        posX -= 2;
        return true;
    }
    else if (posX < 0) {
        posX += 2;
        return true;
    }

    if (posY < 0) {
        posY += 2;
        return true;
    }
    else if(posY > HMAPA * BLOCKSIZE -32){
        posY -=2;
        return true;
    }
    if (posY == BLOCKSIZE * 25 - 32) {
        posY -= 2;
        return true;
    }

    return false;
}
void subir(int x, int y, float &tela) {

    int dx = x / BLOCKSIZE;
    int dy = y / BLOCKSIZE;
    int dx1 = (x + 25) / BLOCKSIZE;
    int dy1 = (y + 25) / BLOCKSIZE;

    if (mapa[dy][dx] == 6) {
        tela += 25 * BLOCKSIZE;
        for(dx = 0; dx < WMAPA; dx++)
            mapa[dy][dx] = 4;
    }
    else if (mapa[dy][dx1] == 6) {
        tela += 25 * BLOCKSIZE;
        for (dx = 0; dx < WMAPA; dx++)
            mapa[dy][dx] = 4;
    }
    else if (mapa[dy1][dx] == 6) {
        tela += 25 * BLOCKSIZE;
        for (dx = 0; dx < WMAPA; dx++)
            mapa[dy][dx] = 4;
    }
    else if (mapa[dy1][dx1] == 6) {
        tela += 25 * BLOCKSIZE;
        for (dx = 0; dx < WMAPA; dx++)
            mapa[dy][dx] = 4;
    }
}
void DrawMap() {
    for (int i = 0; i < HMAPA; i++) {
        for (int j = 0; j < WMAPA; j++) {
            al_draw_bitmap(blocos[mapa[i][j]], j * BLOCKSIZE, i * BLOCKSIZE, 0);
        }
    }
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


    ALLEGRO_BITMAP* galinha = al_load_bitmap("sprites/galinha.png");
    Fusca fusca;
    fusca.sprite = al_load_bitmap("sprites/fusca.png");
    fusca.DefaultDimension();
    fusca.DefaultSpeed();
    fusca.posX = 1;
    fusca.posY = 41 * 32;
    fusca.active = true;
    fusca.left = true;

    ALLEGRO_TIMER* timer = al_create_timer(1.0/90.0);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    bool keys[4] = { false, false, false, false };

    float frame = 1.f;
    int current_frame_y = 0;
    int posX = (WMAPA * BLOCKSIZE / 2) - 16;
    int posY = HMAPA * BLOCKSIZE - 64;

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

        if(events.type == ALLEGRO_EVENT_KEY_DOWN){
            int keycode = events.keyboard.keycode;
            switch (keycode) {
                case ALLEGRO_KEY_W: {
                    keys[W] = true;
                    current_frame_y = 0;
                    break;
                }
                case ALLEGRO_KEY_S: {
                    keys[S] = true;
                    current_frame_y = 32 * 2;
                    break;
                }
                case ALLEGRO_KEY_A: {
                    keys[A] = true;
                    current_frame_y = 32 * 3;
                    break;
                }
                case ALLEGRO_KEY_D: {
                    keys[D] = true;
                    current_frame_y = 32;
                    break;
                }
            }
                
        }
        if(events.type == ALLEGRO_EVENT_KEY_UP) {
            int keycode = events.keyboard.keycode;

            if (keycode == ALLEGRO_KEY_ESCAPE) {
                break;
            }
            switch (keycode) {
                case ALLEGRO_KEY_W: {
                    keys[W] = false;
                    break;
                }
                case ALLEGRO_KEY_S: {
                    keys[S] = false;
                    break;
                }
                case ALLEGRO_KEY_A: {
                    keys[A] = false;
                    break;
                }
                case ALLEGRO_KEY_D: {
                    keys[D] = false;
                    break;
                }
            }
        }

        if (keys[W] == true || keys[S] == true || keys[A] == true || keys[D] == true) {
            frame += 0.04f;
            if (frame > 3) {
                frame -= 3;
            }
        }else frame = 1;

        if (!colideBorda(posX, posY)) {
            posX += keys[D];
            posX -= keys[A];
            posY += keys[S];
            posY -= keys[W];
            subir(posX, posY, dy);
        }
  
        al_identity_transform(&transf);
        al_translate_transform(&transf, 0, dy);

        if(fusca.active){
            fusca.move();
            fusca.colide(posX, posY);
        }

        al_use_transform(&transf);
        if (redraw) {
            DrawMap();
            al_draw_bitmap_region(galinha, 32 * (int)frame, current_frame_y, 32, 32, posX, posY, 0);
            fusca.draw();


            al_flip_display();
            redraw = false;
        }
    }

    for (int i = 0; i < 6; i++) {
        al_destroy_bitmap(blocos[i]);
    }

    fusca.destroy();
    al_destroy_display(display);


}