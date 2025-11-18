#include <iostream>

using namespace std;

class Date
{
    const int day;
    int month;
    int year;
public:
    Date(int day, int month, int year) : day{day}, month{month}, year{year} {}
    Date() : Date(1,1,2022) {}

    int getYear()
    {
        return year;
    }
    int getMonth()
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
    //void setDay(int value)
    //{
    //    day = value;
    //}
};

int main()
{
    setlocale(LC_ALL, "");

    const Date today{ 18,11,2025 };
    Date yersterday{ 17,11,2025 };
    cout << "Сегодня " << today.getDay() << "-е число" << endl;
    cout << "Вчера было " << yersterday.getDay() << "-е число" << endl;
    //today.setDay(19);
    //cout << "Сегодня: " << today.getDay() << "." << today.getMonth() << "." << today.getYear() << endl;

    return 0;
}
