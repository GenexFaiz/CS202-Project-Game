
#include"c-game.h"
int MOVING;
CGAME cg;
bool check = true;
bool endGame;
bool checkRender;

void ThreadFunc1() {
	while (check) {
		//system("cls");
		if (!cg.isdead())
		{
			cg.UpLevel();
			cg.updatePosPeople(MOVING);
			cg.updatePosAnimal();
			cg.updatePosVehicle();
			textcolor(10);
			cg.drawGame();
			Sleep(300);
		}
		else {
			system("cls");
			endGame = true;
			GotoXY(50, 15);
			cout << "DEAD";
			GotoXY(45, 16);
			cout << "Play Again (Y/N)";
			break;
		}
	}
	//system("cls");
	//cout << "DEAD";
}

int main(){
	while (true) {
		bool pause = false;
		FixConsoleWindow();
		int chosen = menu();
		gameBackGround();
		check = true;
		checkRender = true;
		endGame = false;
		thread t1(ThreadFunc1);
		while (check) {
			if (!cg.isdead())
			{
				int temp = toupper(_getch());
				if (endGame)
				{
					while (true) {
						int temp = toupper(_getch());
						check = false;
						t1.join();
						cg.resetGame();
						if (temp == 'N')
						{
							return 0;
						}
						else if (temp =='Y')
						{
							system("cls");
							endGame = false;
							break;
						}
					}
				}
				if (temp == 27) {
					check = false;
					t1.join();
					return 0;
				}
				else if (temp == 224) {
					MOVING = toupper(_getch());
				}
				else if (temp == 80) {
					check = false;
					system("cls");
					t1.join();
				}
				else MOVING = temp;
			}
		}
		system("pause");
	}
	return 0;
}
