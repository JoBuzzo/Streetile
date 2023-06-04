class Carro {
public:
	ALLEGRO_BITMAP* sprite;
	int w, h, posX, posY;
	float speed;
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
			posX = 0;
		}
		else if (posX < 0) {
			posX = 40 * (BLOCKSIZE -1);
		}
	}

	virtual void collide(Galinha &galinha) {
		// Calcular as coordenadas dos cantos do carro
		int carroEsq = posX;
		int carroDir = posX + w;
		int carroTopo = posY;
		int carroBase = posY + h;


		// Calcular as coordenadas dos cantos da galinha
		int galinhaEsq = galinha.posX;
		int galinhaDir = galinha.posX + 32;
		int galinhaTopo = galinha.posY;
		int galinhaBase = galinha.posY + 32;

		if (carroEsq < galinhaDir && carroDir > galinhaEsq && carroTopo < galinhaBase && carroBase > galinhaTopo) {
			galinha.posX = (WMAPA * BLOCKSIZE / 2) - 16;
			galinha.posY = HMAPA * BLOCKSIZE - 64;
			galinha.loseLife();
		
		}
	}

};
