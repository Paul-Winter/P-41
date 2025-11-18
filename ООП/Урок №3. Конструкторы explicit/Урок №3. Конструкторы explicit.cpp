#include <iostream>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year) : day{day}, month{month}, year{year}
    {}
    Date(int year) : Date(1, 1, year)
    {}
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
};

void Print(Date date)
{
    cout << date.getDay() << "." << date.getMonth() << "." << date.getYear() << endl;
}

Date currentYear()
{
    return 2025;
}

int main()
{
    setlocale(LC_ALL, "");

    Print(2020);
    Date date = 2010;
    Print(date);
    Date current = currentYear();
    Print(current);

    return 0;
}
