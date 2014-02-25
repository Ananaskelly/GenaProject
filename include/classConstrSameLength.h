#include "math.h"
#include "GeObj.h"

class ConstrSameLength{ //определ€ет, имеют ли отрезки одинаковую длину
	double *x11, *y11, *x12, *y12;
	double *x21, *y21, *x22, *y22;
public:
	ConstrSameLength(){x11=0, y11=0, x12=0, y12=0, x21=0, y21=0, x22=0, y22=0;};
	ConstrSameLength(GePoint &vbeg1, GePoint &vend1, GePoint &vbeg2, GePoint &vend2){
		x11 = &vbeg1.x;
		y11 = &vbeg1.y;
		x12 = &vend1.x;
		y12 = &vend1.y;
		x21 = &vbeg2.x;
		y21 = &vbeg1.y;
		x22 = &vend2.x;
		y22 = &vend2.y;
	};
	ConstrSameLength(GeLine &l1, GeLine &l2){
		x11 = &l1.beg.x;
		y11 = &l1.beg.y;
		x12 = &l1.end.x;
		y12 = &l1.end.y;
		x21 = &l2.beg.x;
		y21 = &l2.beg.y;
		x22 = &l2.end.x;
		y22 = &l2.end.y;
	};
	double error();
};


double ConstrSameLength::error(){
	double vx1, vy1, vx2, vy2;
	double length1, length2;
	vx1 = abs(x11 - x12);
	vy1 = abs(y11 - y12);
	vx2 = abs(x21 - x22);
	vy2 = abs(y21 - y22);
	length1 = sqrt(vx1*vx1 + vy1*vy1);
	length2 = sqrt(vx2*vx2 + vy2*vy2);
	if (length1 == length2) return 0;
	else 
		return (abs(length1 - length2));
}