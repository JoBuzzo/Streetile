class Carro {
public:
	ALLEGRO_BITMAP* sprite;
	int w, h, speed, posX, posY;

	bool left, active;

	Carro() : sprite(nullptr), w(0), h(0), speed(0), posX(0), posY(0), left(false), active(false) {
	}

	virtual void draw() {
		if (active) {
			if (left) {
				al_draw_bitmap(sprite, posX, posY, ALLEGRO_FLIP_HORIZONTAL);
			}
			else {
				al_draw_bitmap(sprite, posX, posY, 0);
			}
		}
	}

	virtual void destroy() {
		al_destroy_bitmap(sprite);
	}

	virtual void move() {
		posX += speed;
		if (posX > WMAPA * BLOCKSIZE - 32) {
			active = false;
		}
		else if (posX < 0) {
			active = false;
		}
	}

	virtual void colide(int &posX1, int &posY1) {
		// Calcular as coordenadas dos cantos do carro
		int carroEsq = posX;
		int carroDir = posX + w;
		int carroTopo = posY;
		int carroBase = posY + h;


		// Calcular as coordenadas dos cantos da galinha
		int galinhaEsq = posX1;
		int galinhaDir = posX1 + 32;
		int galinhaTopo = posY1;
		int galinhaBase = posY1 + 32;

		if (carroEsq < galinhaDir && carroDir > galinhaEsq && carroTopo < galinhaBase && carroBase > galinhaTopo) {
			posX1 = (WMAPA * BLOCKSIZE / 2) - 16;
			posY1 = HMAPA * BLOCKSIZE - 64;
		}
	}

};
