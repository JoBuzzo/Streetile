class Perua :public Carro {
public:
	Perua() {
		w = 128;
		h = 64;
		speed = 2;
		posX = 1;
		posY = 1;
		active = true;
		left = true;
		sprite = al_load_bitmap("sprites/perua.png");
		delay = 50 * speed;
	}
	void DefaultDimension() {
		w = 128;
		h = 64;
	}
	void setDimension(int w, int h) {
		this->w = w;
		this->h = h;
	}
	void DefaultSpeed() {
		speed = 2;
	}
	void setSpeed(float speed) {
		this->speed = speed;
	}
};