#ifndef _GEOBJ_H
#define _GEOBJ_H

struct selectable{
	bool selected;
};

struct GePoint:public selectable{	
	double x,y;
	GePoint(){x = 0;y = 0;}
	GePoint(double xx,double yy){x = xx;y = yy;}
	GePoint(const GePoint&p){x = p.x;y = p.y; }
};
struct GeLine:public selectable{

};
struct GeCircle:public selectable{

};

#endif