#ifndef _CPEOPLE_H_
#define _CPEOPLE_H_

#include "header.h"
using namespace std;

class CPEOPLE {
	private:
		int x; int y;
	public:
		CPEOPLE();
		void up();
		void down();
		void left();
		void right();
		void render();
};

#endif
