class Van :public Carro {
public:
	Van() {
		w = 120;
		h = 64;
		speed = 3;
		posX = 1;
		posY = 41 * 32;
		active = true;
		left = true;
		sprite = al_load_bitmap("sprites/van.png");
	}

	void DefaultDimension() {
		w = 120;
		h = 64;
	}
	void setDimension(int w, int h) {
		this->w = w;
		this->h = h;
	}
	void DefaultSpeed() {
		speed = 3;
	}
	void setSpeed(float speed) {
		this->speed = speed;
	}
};
