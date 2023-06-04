class FocusRS :public Carro {
public:
	FocusRS() {
		w = 136;
		h = 64;
		speed = 4;
		posX = 1;
		posY = 1;
		active = true;
		left = true;
		sprite = al_load_bitmap("sprites/focusRS.png");
		delay = 50 * speed;
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
		speed = 4;
	}
	void setSpeed(float speed) {
		this->speed = speed;
	}
};
