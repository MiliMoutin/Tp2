#pragma once
#include "Position.h"

typedef struct {
	bool* baldosas;
	int m;
	int n;
}Floor;

typedef Floor* PFloor;

PFloor createFloor(int m, int n);
bool isClean(PFloor f);
bool clean(PFloor f, PPosition p);
void destroyFloor(PFloor f);
bool validRange(PFloor f, PPosition p);
int m(PFloor f);
int n(PFloor f);

