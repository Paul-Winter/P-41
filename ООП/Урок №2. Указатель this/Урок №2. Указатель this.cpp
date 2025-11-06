#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;
public:
    int getX() { return x; }
    int getY() { return y; }

    Point() : x{ 0 }, y{ 0 } {}
    Point(int a) : x{ a }, y{ a } {}
    Point(int pX, int pY) : x{ pX }, y{ pY } {}
};

class Human
{
    char* name;
    int age;
    long id;
public:
    Human(const char* nameP, int ageP, long idP) :
        name{ new char[strlen(nameP) + 1] }, age{ ageP }, id{ idP }
    {
        cout << "Конструктор имени, возраста и паспорта" << endl;
    }
    Human(const char* nameP, int ageP) :
        Human(new char[strlen(nameP) + 1], ageP, 0)
    {
        cout << "Конструктор имени и возраста" << endl;
    }
    Human(const char* nameP) : 
        Human(new char[strlen(nameP) + 1], 0, 0)
    {
        cout << "Конструктор имени" << endl;
    }
    Human() : Human("John Doe", 0, 0)
    {
        cout << "Конструктор по умолчанию" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Point p1;
    Point p2{ 5 };
    Point p3{ 42, 33 };

    Human h1;
    Human h2{ "John Doe" };
    Human h3{ "John Doe", 44 };
    Human h4{ "John Doe", 44, 12345678 };

    return 0;
}
