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

class Bank
{
public:
    int deposit;
    static int budget;
};
int Bank::budget{ 1000000 };

class DateTime
{
    int milliseconds;
    int seconds;
    int minutes;
    int hours;
    int day;
    int week;
    int month;
    int year;

public:
    DateTime(int year, int month, int week, int day, int hours, int minutes, int seconds, int milliseconds)
    {
        this->year = year;
        this->month = month;
        this->week = week;
        this->day = day;
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
        this->milliseconds = milliseconds;
    }

    int getDay()
    {
        return day;
    }
    void setDay(int day)
    {
        this->day = day;
    }

    void Print()
    {
        cout << year << "." << month << "." << day << " " << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Point p1;
    Point p2{ 5 };
    Point p3{ 42, 33 };

    //Human h1;
    //Human h2{ "John Doe" };
    //Human h3{ "John Doe", 44 };
    //Human h4{ "John Doe", 44, 12345678 };

    /*
    Bank filialStavropol{ 50000 };
    Bank filialMikhailovsk{ 30000 };

    cout << "Общий бюджет банка: " << Bank::budget << " рублей" << endl;
    cout << "Ставропольский филиал: " << filialStavropol.deposit << " рублей" << endl;
    cout << "Михайловский филиал: " << filialMikhailovsk.deposit << " рублей" << endl << endl;

    cout << "Ставропольский филиал запросил деньги: " << endl;
    Bank::budget = filialStavropol.budget - 100000;
    filialStavropol.deposit += 100000;
    cout << "Общий бюджет банка: " << Bank::budget << " рублей" << endl;
    cout << "Ставропольский филиал: " << filialStavropol.deposit << " рублей" << endl;
    cout << "Михайловский филиал: " << filialMikhailovsk.deposit << " рублей" << endl << endl;

    cout << "Михайловский филиал запросил деньги: " << endl;
    Bank::budget = filialMikhailovsk.budget - 150000;
    filialMikhailovsk.deposit += 150000;
    cout << "Общий бюджет банка: " << Bank::budget << " рублей" << endl;
    cout << "Ставропольский филиал: " << filialStavropol.deposit << " рублей" << endl;
    cout << "Михайловский филиал: " << filialMikhailovsk.deposit << " рублей" << endl << endl;
    */

    DateTime today{ 2025,11,45,6,19,58,0,0 };
    today.Print();

    return 0;
}
