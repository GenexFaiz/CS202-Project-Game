
#include "header.h"
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void Console_Window_Set()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1000, 500, TRUE);
	Sleep(1000000000);
	MoveWindow(console, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD    result = { 1,1 };
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD                      result = { 1,1 };
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.Y;
}
void window(int x, int y)
{
	int color = 1;
	textcolor(color + 4);
	int w = 50;
	int h = 29;
	gotoxy(x, y);
	cout << char(201);
	for (int i = 2; i < w * 2 + 20; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	//
	for (int j = 1; j <= h; j++)
	{
		gotoxy(x, y + j);
		cout << char(186);
		for (int i = 1; i <= w * 2 - 2 + 20; i++)
		{
			cout << " ";
		}
		cout << char(186);
	}
	//
	cout << endl;
	gotoxy(x, y + h);
	cout << char(200);
	for (int i = 2; i < w * 2 + 20; i++)
	{
		cout << char(205);
	}
	cout << char(188);
	gotoxy(x + 1, y + 1);
}
void Paint(int x, int y, char *a, int color)
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}

int menu()
{
	window(0, 0);
	textcolor(10);
	cout << "        ______________" << endl;
	cout << "       `------------- - '" << endl;
	cout << "     _.  .--./|  |\\.--.._" << endl;
	cout << "    //|  |--||----||--|  |\\" << endl;
	cout << "   ||__\\_|  ||____||  |_/__||" << endl;
	cout << "   ||_-- |__|||==|||__|--_||" << endl;
	cout << "   ||_() |___||--||___| ()_||" << endl;
	cout << "   || --_|   ||__||   |_-- ||" << endl;
	cout << "   ||||  |---||__||---|  ||||" << endl;
	cout << "    \\|| /|___||__||___|\\_||/" << endl;
	cout << "    |||_ | \\.||||||||./ |_|||" << endl;
	cout << "    \\ _ /  \\--==--/ \\ _ /" << endl;
	cout << "     <_> / ----------\\  <_>" << endl;

	cout << "     ||| \\ | \\|  |/|  / |||" << endl;
	cout << "     ||| |  |_|__|_|  | |||" << endl;
	cout << "     ||| [--+ \\  / +--] |||" << endl;
	cout << "     ||| |--+-/  \\-+--| |||" << endl;
	cout << "     ||| |  ||    ||  | |||" << endl;
	cout << "     |=| |___|    |___| |=|" << endl;
	cout << "     / \\ |- -|    |---| / \\" << endl;
	cout << "     |=| | | |    | | | |=|" << endl;
	cout << "     \\ / |___|    |___| \\ /" << endl;
	cout << "      = (| | ||  || | |) =" << endl;
	cout << "         |--_||  ||_--|" << endl;
	cout << "       _ |_#__|  |__#_|_  " << endl;
	cout << "        /______\\ / ______\\" << endl;
	cout << "       |________||________|" << endl;
	textcolor(12);
	GotoXY(35, 2);
	cout << "    ______   ______   ______  ______     ______  ______   _________   ______"; GotoXY(35, 3);
	cout << "	| |  | | | |  | \\ | |     / |        | |____| | | | |  | | | | \\ | |"; GotoXY(35, 4);
	cout << "	| |__| | | |__|_/ | |     '------.   | |  | | | |__| | | | | | | | | |---- "; GotoXY(35, 5);
	cout << "	|_|  |_| |_|      |_|____  ____|_/   |_|__|_| |_|  |_| |_| |_| |_| |_|____"; GotoXY(35, 6);

	GotoXY(65, 10);
	cout << "1.New game" << endl;
	GotoXY(65, 11);
	cout << "2.Load game" << endl;
	GotoXY(65, 12);
	cout << "3.Setting" << endl;
	GotoXY(65, 19);
	cout << "Nguyen Ngoc Thien" << endl;
	GotoXY(65, 20);
	cout << "Nguyen Anh Thu" << endl;
	GotoXY(65, 21);
	cout << "Nguyen Hai Son" << endl;
	GotoXY(65, 22);
	cout << "Do Tri Nhan -^.^-" << endl;
	GotoXY(60, 10);
	cout << ">>";

	char type;
	int chosen = 1;

	type = _getch();
	while (type != 13)
	{
		if (type == 's')
		{
			if (wherey() == 10)
			{
				GotoXY(60, 10);
				cout << "  ";
				GotoXY(60, 11);
				cout << ">>";
				chosen = 2;
			}
			else if (wherey() == 11)
			{
				GotoXY(60, 11);
				cout << "  ";
				GotoXY(60, 12);
				cout << ">>";
				chosen = 3;
			}
			else if (wherey() == 12)
			{
				GotoXY(60, 12);
				cout << "  ";
				GotoXY(60, 10);
				cout << ">>";
				chosen = 1;
			}
		}
		if (type == 'w')
		{
			if (wherey() == 10)
			{
				GotoXY(60, 10);
				cout << "  ";
				GotoXY(60, 12);
				cout << ">>";
				chosen = 3;
			}
			else if (wherey() == 11)
			{
				GotoXY(60, 11);
				cout << "  ";
				GotoXY(60, 10);
				cout << ">>";
				chosen = 1;
			}
			else if (wherey() == 12)
			{
				GotoXY(60, 12);
				cout << "  ";
				GotoXY(60, 11);
				cout << ">>";
				chosen = 2;
			}
		}
		type = _getch();
	}
	return chosen;
}

void gameBackGround()
{
	system("cls");
	GotoXY(35, 2);
	cout << "Win";
	GotoXY(0, 4);
	cout << "CAR================================================================================================================";
	GotoXY(0, 9);
	textcolor(11);
	cout << "DINAUSOR===========================================================================================================";
	GotoXY(0, 14);
	textcolor(12);
	cout << "TRUCK==============================================================================================================";
	GotoXY(0, 19);
	textcolor(13);
	cout << "BIRD================================================================================================================";
	GotoXY(0, 24);
	textcolor(14);
	cout << "====================================================================================================================";
	GotoXY(0, 29);
	cout << "                              ==========================(I AM HERE)=================";
}