class Van :public Carro {
public:
	Van() {
		w = 120;
		h = 64;
		speed = 3;
		posX = 1;
		posY = 1;
		active = true;
		left = true;
		urlSprite = "sprites/van.png";
		sprite = al_load_bitmap(urlSprite);
		delay = 50 * speed;
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
