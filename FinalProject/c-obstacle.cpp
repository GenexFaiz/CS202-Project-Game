#ifndef _COBSTACLE_H_
#define _COBSTACLE_H_

#include "header.h"
using namespace std;

class CVEHICLE {
	int x, y;
public:
	virtual void Move(int, int);
}

class CANIMAL {
	int x, y;
public:
	virtual void Move(int, int);
	virtual void Tell();
}

class CDINAUSOR : public CANIMAL {
public:
	//...
}

class CBIRD : public CANIMAL {
public:
	//...
}

#endif
