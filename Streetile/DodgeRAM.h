class DodgeRAM :public Carro {
public:

	DodgeRAM() {
		w = 148;
		h = 80;
		speed = 4;
		posX = 1;
		posY = 1;
		active = true;
		left = true;
		urlSprite = "sprites/dodgeRAM.png";
		sprite = al_load_bitmap(urlSprite);
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
