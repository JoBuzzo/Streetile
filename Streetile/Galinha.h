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
    void drawHeart() {
        int x = 10;
        for (int i = 0; i < life; i++) {
            al_draw_bitmap(heart, x, 5, 0);
            x += 40;
        }
    }
    void destroyHeart() {
        al_destroy_bitmap(heart);
    }
    void destroy() {
        al_destroy_bitmap(sprite);
    }
    bool borderCollide() {
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
	void keyDOWN(int keycode) {
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
    void keyUP(int keycode) {
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
    void move() {
        if (!borderCollide()) {

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