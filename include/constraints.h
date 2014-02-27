#include "GeObj.h"
#include "math.h"

#ifndef _CONSTRAINTS_H
#define _CONSTRAINTS_H

#define eps 0.001

enum ConstrType{
	CT_ORTHO = 0,
	CT_PARALLEL
};

//constraint on ortho 2 lines
class ConstrOrtho{
	double *x11, *y11, *x12, *y12;
	double *x21, *y21, *x22, *y22;

public:
	ConstrOrtho(){
		x11 = 0; y11 = 0; x12 = 0; y12 = 0;
		x21 = 0, y21 = 0; x22 = 0; y22 = 0;
	};
	
	ConstrOrtho(GeLine &l1, GeLine &l2){
		x11 = &l1.beg.x; y11 = &l1.beg.y; x12 = &l1.end.x; y12 = &l1.end.y;
		x21 = &l2.beg.x, y21 = &l2.beg.y; x22 = &l1.end.x; y22 = &l2.end.y;
	}; 
	double error(){
		double p, p1, q, q1;
		p = *x12 - *x11, p1 = *x22 - *x22;
		q = *y12 - *y11, q1 = *y22 - *y21;
		
		if (p*p1 + q*q1 == 0)
			return 0;
		else{
			double cos;
			cos = (p*p1 + q*q1)/(sqrt(pow(p, 2) + pow(q, 2))*sqrt(pow(p1, 2) + pow(q1, 2)));
			return cos;
		}
	};
};
//constraint on parallel 2 lines
class ConstrParallel{
	double *x11, *y11, *x12, *y12;
	double *x21, *y21, *x22, *y22;

public:
	ConstrParallel(){
		x11 = 0; y11 = 0; x12 = 0; y12 = 0;
		x21 = 0, y21 = 0; x22 = 0; y22 = 0;
	};
	ConstrParallel(GeLine &l1, GeLine &l2){
		x11 = &l1.beg.x; y11 = &l1.beg.y; x12 = &l1.end.x; y12 = &l1.end.y;
		x21 = &l2.beg.x, y21 = &l2.beg.y; x22 = &l1.end.x; y22 = &l2.end.y;
	};
	double error(){
		double p, p1, q, q1;
		p = *x12 - *x11, p1 = *x22 - *x22;
		q = *y12 - *y11, q1 = *y22 - *y21;
		
		if (p * q1 == p1 * q)
			return 1;
		else{
			double cos, sin;
			cos = (p*p1 + q*q1)/(sqrt(pow(p, 2) + pow(q, 2))*sqrt(pow(p1, 2) + pow(q1, 2)));
			sin = sqrt(1 - pow(cos, 2));
			return sin;
		}
	};
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