class Fusca : public Carro{
public:

	Fusca() {
		w = 125;
		h = 32;
		speed = 2;
		posX = 1;
		posY = 41 * 32;
		active = true;
		left = true;
		sprite = al_load_bitmap("sprites/fusca.png");

	}
	void DefaultDimension() {
		w = 125;
		h = 32;
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
