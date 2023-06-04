class FocusRS :public Carro {
public:
	FocusRS() {
		w = 136;
		h = 64;
		speed = 4;
		posX = 1;
		posY = 41 * 32;
		active = true;
		left = true;
		sprite = al_load_bitmap("sprites/focusRS.png");
	}

	void DefaultDimension() {
		w = 136;
		h = 64;
	}
	void setDimension(int w, int h) {
		this->w = w;
		this->h = h;
	}
	void DefaultSpeed() {
		speed = 5;
	}
	void setSpeed(int speed) {
		this->speed = speed;
	}
};
