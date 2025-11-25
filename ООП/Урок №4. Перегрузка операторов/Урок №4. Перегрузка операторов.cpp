#include <iostream>

using namespace std;

class Point
{
public:
    // координаты точки
    int x;
    int y;
    // конструкторы
    Point(int x, int y) : x{ x }, y{ y } {}
    Point() : x{ 0 }, y{ 0 } {}

    // get-методы
    int getX() { return x; }
    int getY() { return y; }

    // set-методы
    void setX(int value) { x = value; }
    void setY(int value) { y = value; }

    // вывод точки на экран
    void print() { cout << "point " << x << ":" << y << endl; }

    // чтение точки
    Point input()
    {
        cout << "input x: ";
        cin >> x;
        cout << endl;
        cout << "input y: ";
        cin >> y;
        cout << endl;
        Point p{ x,y };
        return p;
    }

    // арифметические операции с числом
    Point sum(const Point& p1, int n)
    {        
        return Point(p1.x + n, p1.y + n);
    }
    Point sub(const Point& p1, int n)
    {
        return Point(p1.x - n, p1.y - n);
    }
    Point mul(const Point& p1, int n)
    {
        return Point(p1.x * n, p1.y * n);
    }
    Point div(const Point& p1, int n)
    {
        Point result{ 0,0 };
        if (n != 0)
        {
            result.x = p1.x / n;
            result.y = p1.y / n;
        }
        return result;
    }

    // перегрузка операторов функциями-членами класса
    Point operator++()
    {
        ++this->x;
        ++this->y;
        return *this;
    }
    Point operator--()
    {
        --this->x;
        --this->y;
        return *this;
    }
    const Point operator++(int)
    {
        Point point{ x,y };
        ++(*this);
        return point;
    }
    const Point operator--(int)
    {
        Point point{ x,y };
        --(*this);
        return point;
    }
    Point operator+(const Point& p)
    {
        return Point(this->x + p.x, this->y + p.y);
    }
    Point operator-(const Point& p)
    {
        return Point(this->x - p.x, this->y - p.y);
    }
    Point operator*(const Point& p)
    {
        return Point(this->x * p.x, this->y * p.y);
    }
    Point operator/(const Point& p)
    {
        Point result{ 0,0 };
        if (p.x != 0 && p.y != 0)
        {
            result.x = this->x / p.x;
            result.y = this->y / p.y;
        }
        return result;
    }
    Point operator%(const Point& p)
    {
        Point result{ 0,0 };
        if (p.x != 0 && p.y != 0)
        {
            result.x = this->x % p.x;
            result.y = this->y % p.y;
        }
        return result;
    }

   // арифметические операции между точками
    Point sum(const Point& p1, const Point& p2)
    {       
        return Point(p1.x + p2.x, p1.y + p2.y);
    }
    Point sub(const Point& p1, const Point& p2)
    {
        return Point(p1.x - p2.x, p1.y - p2.y);
    }
    Point mul(const Point& p1, const Point& p2)
    {        
        return Point(p1.x * p2.x, p1.y* p2.y);
    }
    Point div(const Point& p1, const Point& p2)
    {
        Point result{ 0,0 };
        if (p2.x != 0 && p2.y != 0)
        {
            result.x = p1.x / p2.x;
            result.y = p1.y / p2.y;
        }
        return result;
    }

    // перегрузка операторов дружественными функциями
    // сравнение двух точек
    friend bool operator == (const Point& p1, const Point& p2)
    {
        return p1.x == p2.x && p1.y == p2.y;
    }
    friend bool operator != (const Point& p1, const Point& p2)
    {
        return !(p1.x == p2.x && p1.y == p2.y);
    }
    friend bool operator > (const Point& p1, const Point& p2)
    {
        return p1.x > p2.x && p1.y > p2.y;
    }
    friend bool operator < (const Point& p1, const Point& p2)
    {
        return p1.x < p2.x && p1.y < p2.y;
    }
    friend bool operator>=(const Point& p1, const Point& p2)
    {
        return p1.x >= p2.x && p1.y >= p2.y;
    }
    friend bool operator<=(const Point& p1, const Point& p2)
    {
        return p1.x <= p2.x && p1.y <= p2.y;
    }

};

// переопределение операторов глобальными функциями
Point operator+(const Point& p1, const Point& p2)
{
    return Point(p1.x + p2.x, p1.y + p2.y);
}
Point operator-(const Point& p1, const Point& p2)
{
    return Point(p1.x - p2.x, p1.y - p2.y);
}
Point operator*(const Point& p1, const Point& p2)
{
    return Point(p1.x * p2.x, p1.y * p2.y);
}
Point operator/(const Point& p1, const Point& p2)
{
    Point result{ 0,0 };
    if (p2.x != 0 && p2.y != 0)
    {
        result.x = p1.x / p2.x;
        result.y = p1.y / p2.y;
    }
    return result;
}
Point operator-(const Point& p)
{
    return Point(-p.x, -p.y);
}

int main()
{
    setlocale(LC_ALL, "");

    //int x{ 10 };
    //int y{ 10 };
    //cout << "x = " << x << endl;
    //cout << "y = " << y << endl;

    //cout << "++x = " << ++x << endl;
    //cout << "y++ = " << y++ << endl;
    //cout << "y = " << y << endl;

    //cout << "--x = " << --x << endl;
    //cout << "y-- = " << y-- << endl;
    //cout << "y = " << y << endl;

    Point p1{ 11,14 };
    Point p2{ 2,-3 };
    Point p3, p4, p5, p6, p7;
    //p3.sum(p1, p2);
    p1.print();
    p2.print();

    p3 = p1 + p2;
    p3.print();

    p4 = p1 - p2;
    p4.print();

    p5 = p1 * p2;
    p5.print();

    p6 = p1 / p2;
    p6.print();

    p7 = p1 % p2;
    p7.print();

    p1++;
    p2--;
    p1.print();
    p2.print();

    bool point = p1 > p2;
    cout << "p1 > p2 " << point << endl;

    point = p1 < p2;
    cout << "p1 < p2 " << point << endl;

    point = p1 <= p2;
    cout << "p1 <= p2 " << point << endl;

    point = p1 >= p2;
    cout << "p1 >= p2 " << point << endl;

    point = p1 == p2;
    cout << "p1 == p2 " << point << endl;

    point = p1 != p2;
    cout << "p1 != p2 " << point << endl;

    return 0;
}
