#pragma once
#include <vector>
using namespace std;
//!!!!WARNING : SOME OF THESE METHODS MAY WORK CORRECT!!!!


template <class T>
class GeMatrix
{

private:
    int _row, _column;
    T **Data;

public:
	GeMatrix();
	GeMatrix(int row,int column);
	GeMatrix(const GeMatrix &a);
	~GeMatrix(void);


	void Set(int a, int b, T value);
	void Clear();
	void Swap(int s1, int s2);
    int GetColumn();
    int GetRow();

    T** GetPointer();


	bool operator==(GeMatrix<T>& a);
	void operator =(GeMatrix<T>& a);
	void operator<<(GeMatrix<T>& a);
	T*&   operator[](const int);
	GeMatrix<T> operator+(GeMatrix<T>& a);
	GeMatrix<T> operator*(GeMatrix<T>& a);
	void operator+=(GeMatrix<T>& a);

	//double At( int a,int b);
};

template <class T>
GeMatrix<T>::GeMatrix(void)
{
	_row = _column = 0;
}

template <class T>
GeMatrix<T>::GeMatrix(int row,int column)
{
     _row = row; _column = column;
     Data = new T*[row];
     for (int i = 0; i<row; i++)
         Data[i] = new T[column];
 }

template <class T>
GeMatrix<T>::GeMatrix(const GeMatrix& a)
{
    _row = a.GetRow(); _column = a.GetColumn();
    Data = new T*[_row];

    for(int i = 0; i < _row; i++)
        Data[i] = new double[_column];

    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _column; j++)
            Data[i][j]=a[i][j];

 }

template <class T>
void GeMatrix<T>::Clear()
{
	for(int i = 0; i<_row; i++)
		delete[] Data[i];

    delete[] Data;

	_row = _column = 0;
}

template <class T>
void GeMatrix<T>::Set(int a, int b, T value)
{
	Data[a][b] = value;
}

template <class T>
int GeMatrix<T>::GetColumn()
{
    return _column;
}

template <class T>
int GeMatrix<T>::GetRow()
{
    return _row;
}

template <class T>
bool GeMatrix<T>::operator==(GeMatrix<T>& a)
{
    //int aColumn = a.GetColumn(), aRow = a.GetRow(),
	if(a.GetColumn()==_column && a.GetRow()==_row)
	{
		for(int i = 0; i<_row; i++)
			for(int j = 0; j<_column; j++)
				if(Data[i][j]!=a[i][j])
					return 0;
		return 1;
	}
	return 0;
}

template <class T>
void GeMatrix<T>::operator= (GeMatrix<T>& a)
{
	this->Clear();
	_row = a.GetRow(); _column = a.GetColumn();
	Data = new T*[_row];
    for(int i = 0; i<_row; i++)
        Data[i] = new T[_column];

    for(int i = 0; i<_row; i++)
        for(int j = 0; j<_column; j++)
            Data[i][j] = a[i][j];
}

template <class T>
T** GeMatrix<T>::GetPointer()
{
    return Data;
}

template <class T>
void GeMatrix<T>::operator<< (GeMatrix<T>& a) // adress copy
{
    this->Clear();
	Data=a.GetPointer();
	_row = a.GetRow(); _column = a.GetColumn();
}

template <class T>
GeMatrix<T> GeMatrix<T>::operator+(GeMatrix<T>& a)
{
    int aRow = a.GetRow(), aColumn = a.GetColumn();
	GeMatrix<T> newMatrix = GeMatrix(max(_row,aRow),max(_column,aColumn));

	for(int i = 0; i<newMatrix.GetRow(); i++)
    {
        for(int j = 0; j<newMatrix.GetColumn(); j++)
        {
            newMatrix[i][j] = ( (i<_row&&j<_column) ? Data[i][j] : 0 )+ //summary two matrix with different size
                              ( (i<aRow&&j<aColumn) ? a [i][j]   : 0 );
        }
    }
	return newMatrix;
}

template <class T>
void GeMatrix<T>::operator+=(GeMatrix<T>& a)
{
    int row = max(_row, a.GetRow()), column = max(_column,a.GetColumn());
    int aRow = a.GetRow(), aColumn = a.GetColumn();

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<column; j++)
        {
            Data[i][j] = ( (i<_row&&j<_column) ? Data[i][j] : 0 )+ //summary two matrix with different size
                         ( (i<aRow&&j<aColumn) ? a[i][j]    : 0 );
        }
    }

}

template <class T>
GeMatrix<T> GeMatrix<T>::operator*(GeMatrix<T>& a) //!test me PLEASE
{
	GeMatrix<T> newMatrix = GeMatrix(_row,a.GetColumn());
	int nRow = _row, nColumn = a.GetColumn();
    for(int i = 0; i<nRow; i++)
        for(int j = 0; j<nColumn; j++)
        {
            newMatrix[i][j] = 0;
            for(int k = 0;k<_column;k++)
                newMatrix[i][j] += Data[i][k] * a[k][j];
        }
    return newMatrix;
}

template <class T>
T*& GeMatrix<T>::operator[](const int index)
{
    return Data[index];
}

template <class T>
void GeMatrix<T>::Swap(int row1,int row2)
{
	swap(Data[row1],Data[row2]);
}


template <class T>
GeMatrix<T>::~GeMatrix()
{
	Clear();
}


