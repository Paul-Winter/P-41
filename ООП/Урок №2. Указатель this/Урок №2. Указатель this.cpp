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

class Date
{
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year)
    {
        this->year  = year;
        this->month = month;
        this->day   = day;
    }
    Date() : Date(1, 1, 1970) {}

    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }

    void setDay(int day)
    {
        if (day < 1)
        {
            this->day = 1;
        }
        else if (day > 31)
        {
            this->day = 31;
        }
        else
        {
            this->day = day;
        }
    }
    void setMonth(int month)
    {
        if (month < 1)
        {
            this->month = 1;
        }
        else if (month > 12)
        {
            this->month = 12;
        }
        else
        {
            this->month = month;
        }
    }
    void setYear(int year)
    {
        this->year = year;
    }

    void Print()
    {
        cout << day << "." << month << "." << year << endl;
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

    Date today;
    today.Print();

    today.setYear(2025);
    today.setMonth(11);
    today.setDay(11);
    today.Print();

    cout << today.getDay() << "." << today.getMonth() << "." << today.getYear() << endl;

    return 0;
}
