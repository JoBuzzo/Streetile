class Mustang :public Carro {
public:

	Mustang(bool gt = NULL) {
		w = 150;
		h = 64;
		speed = 4;
		posX = 1;
		posY = 1;
		active = true;
		left = true;
		if (gt) {
			sprite = al_load_bitmap("sprites/mustangGT.png");
		}
		else {
			sprite = al_load_bitmap("sprites/mustang.png");
		}
		delay = 50 * speed;
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
		speed = 4;
	}
	void setSpeed(float speed) {
		this->speed = speed;
	}
};
