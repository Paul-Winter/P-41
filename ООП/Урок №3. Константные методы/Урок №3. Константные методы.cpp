#include <iostream>

using namespace std;

class Date
{
    const int currentYear;
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year) : currentYear{ 2025 }, day { day }, month{ month }, year{ year } {}
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
    int getCurrYear() const
    {
        return currentYear;
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

class Account
{
private:
    double sum;
    const double rate;
public:
    Account(double sum, double rate) : sum{ sum }, rate{ rate } {}
    double getSum()
    {
        return sum;
    }
    double getSum() const
    {
        return sum;
    }

    double getRate()
    {
        return rate;
    }
    double getRate() const
    {
        return rate;
    }
    
    void setSum(double value)
    {
        sum = value;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Account account1{ 110.21, 4.5 };
    const Account account2{ 4012.94, 4.9 };


    cout << "Здраствуйте! Спасибо что запустили банк Opat\nВаш баланс: " << account1.getSum() << endl << "Ваш рейтинг в нашем банке: " << account1.getRate() << endl;
    cout << endl << endl << endl;
    cout << "Здраствуйте! Спасибо что запустили банк Opat\nВаш баланс: " << account2.getSum() << endl << "Ваш рейтинг в нашем банке: " << account2.getRate() << endl;
    //const Date today{ 18,11,2025 };
    //Date yesterday{ 18,11,2025 };
    //
    //cout << "Сегодня " << today.getDay() << "-е число" << endl;
    //cout << "Вчера было " << yesterday.getDay() << "-е число" << endl;
    //
    //yesterday.setDay(17);
    //cout << "Вчера было " << yesterday.getDay() << "." << yesterday.getMonth() << "." << yesterday.getYear() << endl;
    //
    //cout << "Сейчас идёт " << today.getCurrYear() << " год" << endl;

    return 0;
}
