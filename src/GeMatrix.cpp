#include "vector"
#include "GeMatrix.h"
using namespace std;
//!!!!WARNING : SOME OF THESE METHODS MAY WORK CORRECT!!!!
 GeMatrix::GeMatrix(void)
{
	n=m=0;
}

 GeMatrix::GeMatrix(int a,int b)
 {
	 Data=new double*[a];
	 for(int i=0;i<a;i++)
		 Data[i]=new double[b];
	 n=a,m=b;
 }

 GeMatrix::GeMatrix(const GeMatrix& a)
 { 
	 Data=new double*[a.n];
		 for(int i=0;i<a.n;i++)
			 Data[i]=new double[a.m];
	 n=a.n,m=a.m;
	 for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		Data[i][j]=a.Data[i][j];
 }
void GeMatrix::Clear()
{
	for(int i=0;i<n;i++)
		delete[] Data[i];
		 delete[] Data;
		 n=m=0;
}

GeMatrix::~GeMatrix()
{
	Clear();
}

void GeMatrix::Set(int a,int b,double value)
{
	Data[a][b]=value;
}

bool GeMatrix::operator==(GeMatrix& a)
{
	if(a.m==this->m&&a.n==this->n)
	{
		for(int i=0;i<a.n;i++)
			for(int j=0;j<a.m;j++)
				if(Data[i][j]!=a.Data[i][j])
					return 0;
		return 1;
	}
	return 0;
}

void GeMatrix::operator= (GeMatrix& a)
{
	this->Clear();
	Data=new double*[a.n];
		 for(int i=0;i<a.n;i++)
			 Data[i]=new double[a.m];
		 n=a.n,m=a.m;
for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		Data[i][j]=a.Data[i][j];
}

void GeMatrix::operator<< (GeMatrix& a) // adress copy
{
	Data=a.Data;
	n=a.n,m=a.m;
}

GeMatrix GeMatrix::operator+(GeMatrix& a)
{
	GeMatrix r=GeMatrix(max(n,a.n),max(m,a.m));
	for(int i=0;i<r.n;i++)
		for(int j=0;j<r.m;j++)
			r.Data[i][j]=((i<n&&j<m)?(Data[i][j]):(0)) + ((i<a.n&&j<a.m)?(a.Data[i][j]):(0));
	return r;
}

void GeMatrix::operator+=(GeMatrix& a)
{
		for(int i=0;i<max(a.n,n);i++)
		for(int j=0;j<max(a.m,m);j++)
			Data[i][j]=((i<n&&j<m)?(Data[i][j]):(0)) + ((i<a.n&&j<a.m)?(a.Data[i][j]):(0));
}

GeMatrix GeMatrix::operator*(GeMatrix& a)
{
	GeMatrix r=GeMatrix(n,a.m);
		for(int i=0;i<r.n;i++)
		for(int j=0;j<r.m;j++)
		{
			r.Data[i][j]=0;
			for(int k=0;k<m;k++)
				r.Data[i][j]+=Data[i][k]*a.Data[k][j];
		}
		return r;
}

void GeMatrix::Swap(int s1,int s2)
{
	swap(Data[s1],Data[s2]);
}

double GeMatrix::At(int a,int b)
{
	return Data[a][b];
}
