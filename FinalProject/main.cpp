#include"header.h"

CPEOPLE a;

bool check = true;
void ThreadFunc1() {
	while (check) {
		system("cls");
		a.render();
		GotoXY(0, 0);
		Sleep(50);
	}
}

int main(){
	FixConsoleWindow();
	thread t1(ThreadFunc1);
	while (true) {
		int temp = toupper(_getch());
		if (temp == 27) {
			check = false;
			t1.join();
			return 0;
		}
		else if (temp == 75) a.left();
		else if (temp == 77) a.right();
		else if (temp == 72) a.up();
		else if (temp == 80) a.down();
	}
}
