#include <iostream>
#include <string.h>

using namespace std;

struct grandFather
{
    int age;
    string name;
};

struct birthDate
{
    int day;
    int month;
    int year;
};
struct student
{
    birthDate date;
    string name;

};
int main()
{
    setlocale(LC_ALL, "");

    int day_ba = 11;
    int month_ba = 12;
    int year_ba = 2009;

    cout << "Бочаров Артём: " << day_ba << "." << month_ba << "." << year_ba << endl;

    int day_dn = 21;
    int month_dn = 07;
    int year_dn = 2008;

    cout << "Дымочкина Настя: " << day_dn << "." << month_dn << "." << year_dn << endl;

    int day_li = 30;
    int month_li = 07;
    int year_li = 2009;

    cout << "Лобозев Илья: " << day_li << "." << month_li << "." << year_li << endl;

    int day_ge = 06;
    int month_ge = 05;
    int year_ge = 2009;

    cout << "Газарян Эдуард: " << day_ge << "." << month_ge << "." << year_ge << endl;
   
    birthDate AD;
    birthDate LI;
    birthDate GE;
    birthDate BA;

    AD.day = 21;
    AD.month = 07;
    AD.year = 2008;

    LI.day = 30;
    LI.month = 07;
    LI.year = 2009;

    GE.day = 06;
    GE.month = 05;
    GE.year = 2009;

    BA.day = 11;
    BA.month = 12;
    BA.year = 2009;

    birthDate arr[4] = { AD,LI,GE,BA };
    for (int i = 0; i < 4; i++)
    {
        cout << "Студент № " << i + 1 << " " << arr[i].day << "." << arr[i].month << "." << arr[i].year << endl;
    }

    student name_AD;
    student name_LI;
    student name_GE;
    student name_BA;

    name_AD.name = "Дымочкина Настя";
    name_BA.name = "Бочаров Артём";
    name_LI.name = "Лобозев Илья";
    name_GE.name = "Газарян Эдуард";

    name_AD.date = AD;
    name_BA.date = BA;
    name_LI.date = LI;
    name_GE.date = GE;

    student mass[4] = { name_AD,name_BA,name_LI,name_GE };

    for (int i = 0; i < 4; i++)
    {
        cout << mass[i].name << ": " << mass[i].date.day << "." << mass[i].date.month << "." << mass[i].date.year << endl;
    }

    return 0;
}
