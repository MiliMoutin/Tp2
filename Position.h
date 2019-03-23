#include "Point.h"
typedef Position* PPosition;

PPosition p(double y, double x, double angle);
bool setCoordinates(PPosition po, double x, double y, double angle);
bool movePoint(PPosition po, double delta, double angle);
PPoint where(PPosition po);