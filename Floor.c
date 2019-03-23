#include <iostream>;
#include "Floor.h";

 
typedef struct {
	bool* baldosas;
	int m;
	int n;
}Floor;


PFloor createFloor(int m, int n) {
	PFloor toret = NULL;
	toret = (PFloor)malloc(sizeof(Floor));
	if (toret != NULL) {
		toret->m = m;
		toret->n = n;
		toret->baldosas = (bool*)malloc(sizeof(bool) *m *n);
		for (int i = 0; i < m*n; i++)
			toret->baldosas[i] = false;
	}
	else {
		free(toret);
	}
	return toret;
}

bool isClean(PFloor p) {
	bool clean = true;
	for (int i = 0; i < p->m*p->n && clean; i++) {
		clean = p->baldosas[i];
	}
	return clean;
}

bool clean(PFloor f, PPoint p) {
	int i = floor(x(p));
	int j = floor(y(p));
	if (*(f->baldosas + (i*f->n) + j) == true) { 
		return false;
	}
	*(f->baldosas + (i*f->n) + j) = true;
	return true;
}

void destroyFloor(PFloor f) {
	free(f->baldosas);
	free(f);
}

bool validRange(PFloor f, PPoint p) {
	return (x(p) < f->m) && (y(p) < f->n);
}


