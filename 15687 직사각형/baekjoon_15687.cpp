#include <iostream>
using namespace std;

class Rectangle {
private:
	int width;
	int height;
public:
	Rectangle(int width, int height) {
		this->width = width;
		this->height = height;
	}

	int get_width() {
		return width;
	}

	int get_height() {
		return height;
	}

	void set_width(int width) {
		if (width <= 0 || width > 1000) {
			return;
		}
		this->width = width;
	}

	void set_height(int height) {
		if (height <= 0 || height > 2000) {
			return;
		}
		this->height = height;
	}

	int area() {
		return width * height;
	}

	int parimeter() {
		return (width * 2) + (height * 2);
	}

	bool is_square() {
		if (width == height) {
			return true;
		}
		else {
			return false;
		}
	}
};