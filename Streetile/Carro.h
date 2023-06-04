class Carro {
public:
	ALLEGRO_BITMAP* sprite;
	int w, h, posX, posY, delay;
	float speed;
	bool left, active;

	Carro() : sprite(nullptr), w(0), h(0), speed(0), posX(0), posY(0), delay(200), left(false), active(false) {
	}

	void setPosX(int value) {
		posX = BLOCKSIZE * value;
	}
	void setPosY(int value) {
		posY = BLOCKSIZE * value;
	}
	void setDirection() {
		posX = BLOCKSIZE * WMAPA;
		left = !left;
		speed = -speed;
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
		if (delay > 0) {
			delay--;
		}
		else {
			posX += speed;

			if (posX > WMAPA * BLOCKSIZE) {
				posX = -w;
				delay = 200;
			}
			else if (posX + w < 0) {
				posX = WMAPA * BLOCKSIZE;
				delay = 200;
			}
		}
	}

	virtual void collide(Galinha &galinha) {
		// Calcular as coordenadas dos cantos do carro
		int carroEsq = posX + 16;
		int carroDir = posX + w - 16;
		int carroTopo = posY + 16;
		int carroBase = posY + h - 16;


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
