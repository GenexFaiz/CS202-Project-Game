
#ifndef _HEADER_H_
#define _HEADER_H_
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<thread>
#include<conio.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
void FixConsoleWindow();
void GotoXY(int x, int y);
//UI
void window(int x, int y); 
void textcolor(int x);
int wherey();
int wherex();
int menu();
void gameBackGround();
#endif
