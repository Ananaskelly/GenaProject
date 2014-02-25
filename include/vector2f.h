#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <math.h>
#include <sstream>
#include <string>

// Класс СВОБОДНЫХ векторов. Быть может  пригодится

// WARNING: особо не тестился, возможны ошибки.

enum DOTPOS {LEFT, RIGHT, BELONG};

class vector2f
{
    public:
        vector2f();
        vector2f(double x, double y);
        vector2f(const vector2f& v);
        virtual ~vector2f();

        double x;
        double y;

        vector2f operator+(vector2f v);
        void operator+=(vector2f v);
        vector2f operator-(vector2f v);
        void operator-=(vector2f v);
        vector2f operator*(double c);
        vector2f operator/(double c);
        bool operator==(vector2f v);
        bool operator!=(vector2f v);

        double length(); // длина вектора
        double length(vector2f v); // длина прямой
        double length2(); // длина вектора в квадрате
        double length2(vector2f v); // квадрат длины прямой
        double dot(vector2f v); // скалярное произведение
        double det(vector2f v); // определитель, построенный по 2м векторам
        double slope(); // угол наклона вектора
        double slope(vector2f v); // угол наклона прямой, проходящей через 2 точки
        vector2f normalize(); // нормализует данный вектор(возвращает вектор равный данному)
        vector2f turn(double a); // поворот вектора  на заданный угол а(в радианах), против часовой стрелки
        vector2f turn(double a, vector2f v); // поворот вектора вокруг заданной точки

        DOTPOS classify(vector2f v0, vector2f v1); // отношение текущей точки, относительно прямой v0v1
        vector2f perp(vector2f v0, vector2f v1); // возвращается перпендикуляр, опускаймый из текущей точки  на прямую v0v1
        double distance(vector2f v0, vector2f v1); // раcстояние  от текущей точки до прямой v0v1
        bool inCircle(vector2f c, double R); // принадлежит ли точка окружности
        std::string toString();
    protected:
    private:
};

// ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ
// пересечение 2х линий; true - возвращает в случае пересечения, false - иначе
// в переменную crs возвращается точка пересечения
bool crossLine(vector2f a0, vector2f a1, vector2f b0, vector2f b1, vector2f *crs);

#endif // VECTOR2F_H
