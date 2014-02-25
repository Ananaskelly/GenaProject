#include<iostream>
#include<cmath>
#include"containt.h"

using namespace std;
//������� ���������� ����� ������ � �������� ����� ������� ������������(��������� � �� ������� ������)
class SbetweenPointandLine{
double *x1,*y1,*x2,*y2,*x3,*y3;
SbetweenPointandLine(){x1=0,y1=0,x2=0,y2=0,x3=0,y3=0;};
SbetweenPointandLine(const SbetweenPointandLine& p){x1=p.x1;y1=p.y1;x2=p.x2;y2=p.y2;x3=p.x3;y3=p.y3;}
bool error();
};

bool SbetweenPointandLine::error(){
	// �������� � �������� ���������� ������� ���������� ���� �����, ������ ��� - ���������� ������ �������, 
	//��������� - ���������� ����� ��� �������
	
	double r1,r2,r3,h,p,S;
	r1=sqrt(pow((x1-x2),2)+pow((y1-y2),2) );
	r2=sqrt(pow((x1-x3),2)+pow((y1-y3),2) );
	r3=sqrt(pow((x2-x3),2)+pow((y2-y3),2) );
	p=(r1+r2+r3)/2;
	S= sqrt(p*(p-r1)*(p-r2)*(p-r3));
	h=(2*S)/r1;
	return h;
	
}
