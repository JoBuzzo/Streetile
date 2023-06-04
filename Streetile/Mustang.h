class Mustang :public Carro {
public:
	Mustang() {
		w = 96;
		h = 64;
		speed = 3;
		posX = 1;
		posY = 41 * 32;
		active = true;
		left = true;
		sprite = al_load_bitmap("sprites/mustang.png");

	}
	void DefaultDimension() {
		w = 96;
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
