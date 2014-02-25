#include "functional"
#include "iostream"
#include "vector"
using namespace std;
#define Function function<double(vector<double>)>
#define Eps 0.15 //
double Derivative(Function func,int dx,vector<double> x)
{
	int f=0;
	vector<double> xx=x;
	vector<double> eps=x;
	xx[dx]+=Eps;
	x[dx]-=Eps;
		return (func(xx)-func(x))/(2*Eps);
	return 0;
}
double Derivative2 (Function func,int dx,vector<double> x)
{
	int f=0;
	vector<double> xx=x;
	xx[dx]+=Eps;
		return (func(xx)-func(x))/(Eps);
	return 0;
}
double MaybeFinalDerivative(Function func,int dx,vector<double> x)
{
	double ar[5][5];
	int n=3;
	double rr=3*x[0]*x[0]+2*x[1]-16*x[1]*x[0];
	vector<double> xx=x;
	xx[dx]+=Eps;
	x[dx]-=Eps;
	double d=2*Eps;
	for(int i=n-1;i>=0;i--)
	{
		ar[0][i]=(func(xx)-func(x))/d;
			xx[dx]+=Eps;
		    x[dx]-=Eps;
			d+=2*Eps;
	}
	for(int i=1;i<n;i++)
		for(int j=0;j<n-i;j++)
			ar[i][j]=ar[i-1][j+1]+(ar[i-1][j+1]-ar[i-1][j])/((1ll<<(2*i))-1.0);
			return ar[n-1][0];
}
