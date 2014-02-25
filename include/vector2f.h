#ifndef VECTOR2F_H
#define VECTOR2F_H

// тестовый класс вектора

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
        vector2f operator+=(vector2f v);
        vector2f operator-(vector2f v);
        vector2f operator-=(vector2f v);
        vector2f operator*(double c);
        vector2f operator/(double c);
        double length(); // длина вектора
        double length(vector2f v); // длина прямой
        double length2(); // длина вектора в квадрате
        double length2(vector2f v); // квадрат длины прямой
        double dot(vector2f v); // скалярное произведение
        double det(vector2f v); // определитель, построенный по 2м векторам
        double slope(); // угол наклона вектора
        double slope(vector2f v); // угол наклона прямой, проходящей через 2 точки
        vector2f normalize(); // нормализует данный вектор(и возвращает вектор равный данному)
        vector2f turn(double a); // поворот вектора  на заданный угол а(в радианах), против часовой стрелки
        vector2f turn(double a, vector2f v); // поворот вектора вокруг заданной точки
    protected:
    private:
};

#endif // VECTOR2F_H
