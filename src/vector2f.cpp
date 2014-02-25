#include "../include/vector2f.h"

vector2f::vector2f()
{
    x = 0; y = 0;
}

vector2f::vector2f(double x, double y)
{
    this->x = x;
    this->y = y;
}

vector2f::vector2f(const vector2f& v)
{
    x = v.x; y = v.y;
}

vector2f::~vector2f()
{
    //dtor
}

vector2f vector2f::operator+(vector2f v)
{
    return vector2f(x + v.x, y + v.y);
}

void vector2f::operator+=(vector2f v)
{
    x += v.x;
    y += v.y;
}

vector2f vector2f::operator-(vector2f v)
{
    return vector2f(x - v.x, y - v.y);
}

void vector2f::operator-=(vector2f v)
{
    x -= v.x;
    y -= v.y;
}

vector2f vector2f::operator*(double c)
{
    return vector2f(x * c, y * c);
}

vector2f vector2f::operator/(double c)
{
    if (c != 0)
    return vector2f(x / c, y / c);

    return vector2f(0, 0);
}

bool vector2f::operator==(vector2f v)
{
    return (x == v.x && y == v.y);
}

bool vector2f::operator!=(vector2f v)
{
    return (x != v.x || y != v.y);
}

double vector2f::length2()
{
    return x * x + y * y;
}

double vector2f::length2(vector2f v)
{
    return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y);
}

double vector2f::length()
{
    return sqrt(x * x + y * y);
}

double vector2f::length(vector2f v)
{
    return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
}

double vector2f::dot(vector2f v)
{
    return x * v.y + y * v.x;
}

double vector2f::det(vector2f v)
{
    return x * v.y - y * v.x;
}

vector2f vector2f::normalize()
{
    double l = length();
    x /= l; y /= l;
    return *this;
}

double vector2f::slope()
{
    return atan2(y, x);
}

double vector2f::slope(vector2f v)
{
    //return atan2(v.y-y, v.x-x);
    return atan2(v.y - y, v.x - x);
}

vector2f vector2f::turn(double a)
{
    double l = length();
    a += slope();
    x = l * cos(a);
    y = l * sin(a);
    return *this;
}

vector2f vector2f::turn(double a, vector2f v)
{
    double l = length(v);
    a += v.slope(*this);
    this->x = v.x + l * cos(a);
    this->y = v.y + l * sin(a);
    return *this;
}

// положение текущей точки относительно прямой v0v1
// 0> - слева, 0< - справа, 0= - непосредственно на прямой
DOTPOS vector2f::classify(vector2f v0, vector2f v1)
{
    vector2f a = v1 - v0;
    vector2f b = *this - v0;

    double dp = a.x * b.y - b.x * a.y;
	if (dp == 0) return BELONG;
	if (dp < 0) return LEFT;
	return RIGHT;
}

vector2f vector2f::perp(vector2f v0, vector2f v1)
{
    vector2f vec = v1 - v0;
    double t = vec.dot(*this - v0) / vec.length();

    return v0 + (vec.normalize() * t);
}

double vector2f::distance(vector2f v0, vector2f v1)
{
    return perp(v0, v1).length();
}

bool vector2f::inCircle(vector2f c, double R)
{
    if ((*this - c).length() <= R) return true;
    return false;
}

std::string vector2f::toString()
{
    std::ostringstream str;
    str << "[" << x << ", " << y << "]\n";
    return str.str();
}

//////

bool crossLine(vector2f a0, vector2f a1, vector2f b0, vector2f b1, vector2f *crs)
{
    vector2f a, b;
    a = a1 - a0;
    b = b1 - b0;

    if (a.det(b) == 0) return false;

	double t, d, dt;

    if (b.x == 0)
        t = (b0.x - a0.x)/a.x;
    else
    if (b.y == 0)
        t = (b0.y - a0.y)/a.y;
    else
    {
        d = b.x / b.y;
        dt = a.x - d*a.y;

        t = ((b0.x - a0.x) - (b0.y - a0.y)*d)/dt;
    }

    crs->x = a0.x + t*a.x;
    crs->y = a0.y + t*a.y;

	return true;
}
