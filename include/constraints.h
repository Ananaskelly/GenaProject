#include "GeOBJ.h"
#include "math.h"

#ifndef _CONSTRAINTS_H
#define _CONSTRAINTS_H

#define eps 0.001

enum ConstrType{
	CT_ORTHO = 0,
	CT_PARALLEL
};
//constraint on ortho 2 lines
class ConstrOrto
{
	double *x11, *y11, *x12, *y12;
	double *x21, *y21, *x22, *y22;

public:
	ConstrOrto(GeLine &l1, GeLine &l2);
	double error();


};
//constraint on parallel 2 lines
class ConstrParallel
{
	double error();
};
//constraint "Is point on the line?"
class ConstrPoOnLine
{
	double error();
};
class LengthBetweenPoints
{
	double x1, y1;
	double x2, y2;

public:
	LengthBetweenPoints(GePoint &p1, GePoint &p2){x1=p1.x; y1=p1.y; x2=p2.x; y2=p2.y;};
	double error(double distance);
};

double LengthBetweenPoints::error(double length1)
{
	double length2;
	length2=sqrt(pow((x1-x2),2.)+pow((y1-y2),2.));
	if (length2-length1 < eps)
		return 0;
	else
		return abs(length1-length2);
}
class CoincidencePoints
{
	double x1, y1;
	double x2, y2;

public:
	CoincidencePoints(GePoint &p1, GePoint &p2){x1=p1.x; y1=p1.y; x2=p2.x; y2=p2.y;};
	double error();
};
double CoincidencePoints::error()
{
	double length;
	length=sqrt(pow((x1-x2),2.)+pow((y1-y2),2.));
	if (length < eps)
		return 0;
	else
		return abs(length);
}
class PointOnCircle
{
	double x, y;
	double x2, y2, R;
public:
	PointOnCircle(GePoint &p, GeCircle &c){x=p.x; y=p.y; x2=c.x; y2=c.y; R=c.R;};
	double error();

};
double PointOnCircle::error()
{
	double res=0;
	if ((x*x-x2*x2)*(x*x-x2*x2) + (y*y-y2*y2)*(y*y-y2*y2) - R*R < eps)
		return 0;
	else
		return ( sqrt(pow((x-x2),2.) + pow((y-y2),2.)) - R);
}

#endif