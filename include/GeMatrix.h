#pragma once
class GeMatrix
{
public:
	GeMatrix(void);
	GeMatrix(int a,int b);
	GeMatrix(const GeMatrix &a);
	~GeMatrix(void);
	int n,m;
	double** Data;
	void Set(int a,int b,double value);
	void Clear();
	bool operator==(GeMatrix& a);
	void operator =(GeMatrix& a);
	void operator<<(GeMatrix& a);
	GeMatrix operator+(GeMatrix& a);
	GeMatrix operator*(GeMatrix& a);
	void operator+=(GeMatrix& a);
	void Swap(int s1,int s2);
	double At( int a,int b);
};

