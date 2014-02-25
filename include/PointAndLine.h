#include<iostream>
#include"containt.h"

class PandL{
// передаем в качестве аргументов функции координаты трех точек, первые две - координаты концов отрезка, 
//последняя - координаты точки 
	double *x1,*y1,*x2,*y2,*x3,*y3;
	PandL(){x1=0,y1=0,x2=0,y2=0,x3=0,y3=0;};
    PandL(const PandL& p){x1=p.x1;y1=p.y1;x2=p.x2;y2=p.y2;x3=p.x3;y3=p.y3;}
	double error();
};
double PandL::error(){
	if((x3-x1)*(y2-y1)==(y3-y1)*(x2-x1))
	{
		return 0;
	
    }

	else 
		{
			return //;
	    }
}