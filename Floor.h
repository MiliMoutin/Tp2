#include "Point.h";
typedef Floor* PFloor;

PFloor createFloor(int m, int n);
bool isClean(PFloor f);
bool clean(PFloor f, PPoint p);
void destroyFloor(PFloor f);