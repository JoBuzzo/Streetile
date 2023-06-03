class Galinha {
public:
	ALLEGRO_BITMAP* sprite;
    ALLEGRO_BITMAP* heart;


	int w, h, posX, posY, current_frame_y, life;
	float frame;
    enum KEYS { W, S, A, D };
	bool keys[4] = { false, false, false, false };

	Galinha() {
		w = 32;
		h = 32;
		sprite = al_load_bitmap("sprites/galinha.png");
        heart = al_load_bitmap("sprites/heart.png");
		posX = (WMAPA * BLOCKSIZE / 2) - 16;
		posY = HMAPA * BLOCKSIZE - 64;
		current_frame_y = 0;
		frame = 1.f;
        life = 2;
	}
	void draw() {
		if (keys[W] == true || keys[S] == true || keys[A] == true || keys[D] == true) {
			frame += 0.04f;
			if (frame > 3) {
				frame -= 3;
			}
		}
		else frame = 1;

		al_draw_bitmap_region(sprite, 32 * (int)frame, current_frame_y, 32, 32, posX, posY, 0);
	}
    void drawHeart(float dy) {
        int x = 10;
        for (int i = 0; i < life; i++) {
            al_draw_bitmap(heart, x, -dy, 0);
            x += 40;
        }
    }
    void destroyHeart() {
        al_destroy_bitmap(heart);
    }
    void destroy() {
        al_destroy_bitmap(sprite);
    }
    bool colideBorda() {
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
        else if (posY > HMAPA * BLOCKSIZE - 32) {
            posY -= 2;
            return true;
        }
        if (posY == BLOCKSIZE * 25 - 32) {
            posY -= 2;
            return true;
        }

        return false;
    }
    void reScreen(float& tela) {

        int dx = posX / BLOCKSIZE;
        int dy = posY / BLOCKSIZE;
        int dx1 = (posX + 32) / BLOCKSIZE;
        int dy1 = (posY + 32) / BLOCKSIZE;

        if (mapa[dy][dx] == 6) {
            tela += 25 * BLOCKSIZE;
            for (dx = 0; dx < WMAPA; dx++)
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
	void move(ALLEGRO_EVENT events) {
        if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
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
        if (events.type == ALLEGRO_EVENT_KEY_UP) {
            int keycode = events.keyboard.keycode;

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
        if (!colideBorda()) {
            posX += keys[D];
            posX -= keys[A];
            posY += keys[S];
            posY -= keys[W];
        }
	}
    void loseLife() {
        if(life > 0)
            life--;
    }

};