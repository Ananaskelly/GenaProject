#include "ConstrCircleContact.h"
#include <math.h>


bool ConstrCircleContact::isOUT (double& a, double& b, double& x, double& y, double& r)
{
	if ((pow((x-a),2)+pow((y-b),2))>pow(r,2)) return true;
	return false;
}
double ConstrCircleContact::error_in (double& a, double& b, double& x, double& y, double& r, double &R)
{
	return (R-(sqrt(pow(x-a,2)+pow(x-b,2))+r));
}

double ConstrCircleContact::error_out(double& a, double& b, double& x, double& y, double& r, double &R)
{
	return sqrt(pow((x-a),2)+pow((y-b),2))-R+r;
}
