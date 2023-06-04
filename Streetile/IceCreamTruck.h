class IceCreamTruck :public Carro{
public:
	IceCreamTruck() {
		w = 180;
		h = 96;
		speed = 2;
		posX = 1;
		posY = 1;
		active = true;
		left = true;
		sprite = al_load_bitmap("sprites/IceCreamTruck.png");
		delay = 50 * speed;
	}

	void DefaultDimension() {
		w = 180;
		h = 96;
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

