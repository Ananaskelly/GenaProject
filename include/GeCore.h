#pragma once
#include "GeList.h"
#include "GeObj.h"
#include "constraints.h"
typedef int UID;


class GeCore
{
	//GeUI _ui;
	// Список точек
	GeList<GePoint> _points;
	// Список отрезков

	// Список окружностей

public:
	GeCore(void);
	~GeCore(void);
	UID addPoint(double x, double y){ _points.add(GePoint(x,y));};
	UID addLine(double x1, double y1,double x2, double y2);
	UID addCircle(double x, double y,double R);

	UID addConstraint(ConstrType type, UID obj1,UID obj2);

	// выбор объекта, находящегося ближе всего к точке (x,y)
	void selectObject(double x,double y); 
	UID addConstraint(ConstrType type);

	void remove(UID);
};

