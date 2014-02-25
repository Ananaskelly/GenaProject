#ifndef _GEOBJ_H
#define _GEOBJ_H

struct GePoint{
	double x,y;
	GePoint(){x = 0;y = 0;}
	GePoint(double xx,double yy){x = xx;y = yy;}
	GePoint(const GePoint&p){x = p.x;y = p.y; }
};
struct GeLine{};
struct GeCircle{};

#endif