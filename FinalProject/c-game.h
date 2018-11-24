
#ifndef _CGAME_H_
#define _CGAME_H_
#include "header.h"
#include "c-people.h"
#include "c-obstacle.h"
class CGAME {
private:
	int LEVEL;
	CTRUCK* axt;
	CCAR* axh;
	CDINAUSOR* akl;
	CBIRD* ac;
	CPEOPLE cn;
public:
		CGAME() //Chuẩn bị dữ liệu cho tất cả các đối tượng
		{
			LEVEL = 1;
				axh = new CCAR[LEVEL];
				axt = new CTRUCK[LEVEL];
				akl = new CDINAUSOR[LEVEL];
				ac = new CBIRD[LEVEL];
				srand(time(NULL));
				int Nran1 = rand() % 95 + 1; if (Nran1 % 2 == 0) Nran1--;
				int Nran2 = rand() % 95 + 1; if (Nran2 % 2 == 0) Nran2--;
				int Nran3 = rand() % 95 + 1; if (Nran3 % 2 == 0) Nran3--;
				int Nran4 = rand() % 95 + 1; if (Nran4 % 2 == 0) Nran4--;
				//Nran1 = 1; Nran2 = 3; Nran3 = 5; Nran4 = 7;
				for (int i = 0; i < LEVEL ; i++)
				{
					axh[i].Set(Nran1 - (100/LEVEL) * i, 5);
					axt[i].Set(Nran2 - (100 / LEVEL)  * i, 15);
					akl[i].Set(Nran3 + (100 / LEVEL) * i, 10);
					ac[i].Set(Nran4 + (100 / LEVEL) * i, 20);
				}
		}
		void drawGame() //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
		{
			GotoXY(2, 2); cout << "Level: "<<LEVEL;
			cn.render();
			for (int i = 0; i < LEVEL ; i++)
			{
				axh[i].render();
				akl[i].render();
				axt[i].render();
				ac[i].render();
			}
		}
		~CGAME() // Hủy tài nguyên đã cấp phát
		{
			delete []axh ;
			delete[]axt;
			delete[]akl;
			delete[]ac;
		}
		CPEOPLE getPeople();//Lấy thông tin người
		CVEHICLE* getVehicle();//Lấy danh sách các xe
		CANIMAL* getAnimal(); //Lấy danh sách các thú
		void UpLevel()
		{
			if (this->cn.isFinish())
			{
				system("cls");
				GotoXY(50, 15);
				cout << "Congratulations! Level up";
				Sleep(1000);
				system("cls");
				delete[]axh;
				delete[]axt;
				delete[]akl;
				delete[]ac;
				LEVEL++;
				if (LEVEL == 5)
				{
					GotoXY(50, 15);
					cout << "MAX LEVEL, so profesional" << endl;
					cout << "RESET";
					Sleep(1000);
					LEVEL = 1;
				}
				axh = new CCAR[LEVEL];
				axt = new CTRUCK[LEVEL];
				akl = new CDINAUSOR[LEVEL];
				ac = new CBIRD[LEVEL];
				srand(time(NULL));
				int Nran1 = rand() % 95 + 1; if (Nran1 % 2 == 0) Nran1--;
				int Nran2 = rand() % 95 + 1; if (Nran2 % 2 == 0) Nran2--;
				int Nran3 = rand() % 95 + 1; if (Nran3 % 2 == 0) Nran3--;
				int Nran4 = rand() % 95 + 1; if (Nran4 % 2 == 0) Nran4--;
				//Nran1 = 1; Nran2 = 3; Nran3 = 5; Nran4 = 7;
				for (int i = 0; i < LEVEL; i++)
				{
					axh[i].Set(Nran1 - (100 / LEVEL) * i, 5);
					axt[i].Set(Nran2 - (100 / LEVEL)  * i, 15);
					akl[i].Set(Nran3 + (100 / LEVEL) * i, 10);
					ac[i].Set(Nran4 + (100 / LEVEL) * i, 20);
				}
				
				gameBackGround();
				this->cn.initial();
			}
			else return;
		}
		void resetGame() // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
		{
			LEVEL = 1;
			axh = new CCAR[LEVEL];
			axt = new CTRUCK[LEVEL];
			akl = new CDINAUSOR[LEVEL];
			ac = new CBIRD[LEVEL];
			srand(time(NULL));
			int Nran1 = rand() % 95 + 1; if (Nran1 % 2 == 0) Nran1--;
			int Nran2 = rand() % 95 + 1; if (Nran2 % 2 == 0) Nran2--;
			int Nran3 = rand() % 95 + 1; if (Nran3 % 2 == 0) Nran3--;
			int Nran4 = rand() % 95 + 1; if (Nran4 % 2 == 0) Nran4--;
			//Nran1 = 1; Nran2 = 3; Nran3 = 5; Nran4 = 7;
			for (int i = 0; i < LEVEL; i++)
			{
				axh[i].Set(Nran1 - (100 / LEVEL) * i, 5);
				axt[i].Set(Nran2 - (100 / LEVEL)  * i, 15);
				akl[i].Set(Nran3 + (100 / LEVEL) * i, 10);
				ac[i].Set(Nran4 + (100 / LEVEL) * i, 20);
			}
			gameBackGround();
			cn.initial();
		}
		void exitGame(HANDLE); // Thực hiện thoát Thread
		void startGame(); // Thực hiện bắt đầu vào trò chơi
		void loadGame(istream); // Thực hiện tải lại trò chơi đã lưu
		void saveGame(istream); // Thực hiện lưu lại dữ liệu trò chơi
		void pauseGame(HANDLE); // Tạm dừng Thread
		void resumeGame(HANDLE); //Quay lai Thread
		void updatePosPeople(int &MOVING) //Thực hiện điều khiển di chuyển của CPEOPLE
		{
			if (MOVING == -1) return;
			if (MOVING == 75) { cn.left(); MOVING = -1; }
			else if (MOVING == 77) { cn.right(); MOVING = -1; }
			else if (MOVING == 72) { cn.up(); MOVING = -1; }
			else if (MOVING == 80) { cn.down(); MOVING = -1; }
		}
		void updatePosVehicle() //Thực hiện cho CTRUCK & CCAR di chuyển
		{
			CVEHICLE *ve;
			for (int i = 0; i < LEVEL; i++)
			{
				ve = &axh[i];
				ve->Move();
				ve = &axt[i];
				ve->Move();
			}
		}
		void updatePosAnimal()//Thực hiện cho CDINAUSOR & CBIRD di chuyển
		{
			CANIMAL *an;
			for (int i = 0; i < LEVEL; i++)
			{
				an = &akl[i];
				an->Move();
				an = &ac[i];
				an->Move();
			}
		}
		bool isdead()
		{
			/*
			CVEHICLE **b;
			
			b = new CVEHICLE*[LEVEL * 2];
			CANIMAL **a;
			a = new CANIMAL*[LEVEL * 2];
			for (int i = 0; i < LEVEL * 2; i+=2)
			{
				a[i] = &ac[i];
				a[i + 1] = &akl[i];
			}
			for (int i = 0; i < LEVEL * 2; i += 2)
			{
				b[i] = &axh[i];
				b[i + 1] = &axt[i];
			}
			return this->cn.isDead(a,b);
			*/
			
			/////////////////////////////////////////////////////
			
			vector<CVEHICLE*> b;
			vector<CANIMAL*> a;
			CVEHICLE* B;
			CANIMAL*A;
			for (int i = 0; i < LEVEL*2; i+=2)
			{
				A = new CBIRD;
			    A = &ac[i];
				a.push_back(A);
				A = new CDINAUSOR;
				A = &akl[i];
				a.push_back(A);
			}
			for (int i = 0; i < LEVEL*2; i+=2)
			{
				B = new CTRUCK;
				B = &axt[i];
				b.push_back(B);
				B = new CCAR;
				B = &axh[i];
				b.push_back(B);
			}
			return this->cn.isDead(a,b);
			
			



			/*
			for (int i = 0; i < LEVEL; i++)
			{
			a[i] = &ac[i];
			}
			for (int i = LEVEL; i < LEVEL*2; i++)
			{
			a[i] = &akl[i];
			}
			for (int i = 0; i < LEVEL; i++)
			{
			b[i] = &axh[i];
			}
			for (int i = LEVEL; i < LEVEL * 2; i++)
			{
			b[i] = &axt[i];
			}
			*/
		}
};

#endif
