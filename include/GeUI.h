
#include <stdlib.h>
#include <glut.h>
#pragma once

#define func void (*func)(void)

class GeUI
{
	//GeCore *_core;
public:
	GeUI();
	~GeUI(void);

	//func MyDraw;
	void (*MyDraw)(void);

	void init(int *argc, char ** argv);
	//void setCore(GeCore* );

	//void drawPoint(double x,double y);
	//void drawLine(double x1, double y1,double x2, double y2);
	//void drawCircle(double x, double y,double R);
private:
	void draw();

};

void drawLine(double x0, double y0, double x1, double y1);

