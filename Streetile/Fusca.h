class Fusca : public Carro{
public:

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

	void setSpeed(int speed) {
		this->speed = speed;
	}

};
