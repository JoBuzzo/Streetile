class DodgeRAM :public Carro {
public:

	DodgeRAM() {
		w = 148;
		h = 70;
		speed = 4;
		posX = 1;
		posY = 1;
		active = true;
		left = true;
		sprite = al_load_bitmap("sprites/dodgeRAM.png");
		delay = 50 * speed;
	}

	void DefaultDimension() {
		w = 148;
		h = 80;
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
