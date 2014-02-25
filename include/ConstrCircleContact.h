#pragma once
class ConstrCircleContact
{
public:
	ConstrCircleContact();
	
	bool isOUT(double& a, double& b, double& x, double& y, double& r);

	double error_in(double& a, double& b, double& x, double& y, double& r, double &R);
	double error_out(double& a, double& b, double& x, double& y, double& r, double &R);

};
