#include"c-people.h"

CPEOPLE::CPEOPLE() {
	x = 0;
	y = 0;
}

void CPEOPLE::right() {
	if (x < 100) x++;
}

void CPEOPLE::left() {
	if (x > 0) x--;
}

void CPEOPLE::up() {
	if (y > 0) y--;
}

void CPEOPLE::down() {
	if (y < 100) y++;
}

void CPEOPLE::render() {
	GotoXY(x, y);
	cout << "Y";
}