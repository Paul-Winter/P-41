#include <iostream>

using namespace std;

class Date
{
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year) : day{day}, month{month}, year{year} {}
    Date() : Date(1,1,2022) {}

    int getYear()
    {
        return year;
    }
    int getYear() const
    {
        return year;
    }
    int getMonth()
    {
        return month;
    }
    int getMonth() const
    {
        return month;
    }
    int getDay()
    {
        return day;
    }
    int getDay() const
    {
        return day;
    }

    void setYear(int value)
    {
        year = value;
    }
    void setMonth(int value)
    {
        month = value;
    }
    void setDay(int value)
    {
        day = value;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    const Date today{ 18,11,2025 };
    Date yesterday{ 18,11,2025 };

    cout << "Сегодня " << today.getDay() << "-е число" << endl;
    cout << "Вчера было " << yesterday.getDay() << "-е число" << endl;

    yesterday.setDay(17);
    cout << "Вчера было " << yesterday.getDay() << "." << yesterday.getMonth() << "." << yesterday.getYear() << endl;

    return 0;
}
