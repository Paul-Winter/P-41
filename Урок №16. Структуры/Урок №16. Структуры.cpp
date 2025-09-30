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
struct date_
{
    int day;
    int month;
    int year;
    int number;
    int number_month;
    string name;
};
struct test
{
    char c;
    int i;
};

void show(grandFather g)
{
    cout << "\n\nДедушка:" << endl;
    cout << "\nЛет: " << g.age;
    cout << "\nИмя: " << g.name;
}
void show(date_ d)
{
    cout << "\n\nДата:" << endl;
    cout << "\nДень: " << d.day;
    cout << "\nМесяц: " << d.month;
    cout << "\nГод: " << d.year;
    cout << "\nНомер дня: " << d.number;
    cout << "\nНомер месяца: " << d.number_month;
    cout << "\nНазвание:" << d.name;
}
void show(birthDate b)
{
    cout << "\n\n___День рождения:___" << endl;
    cout << "\nДень рождения: " << b.day;
    cout << "\nМесяц рождения: " << b.month;
    cout << "\nГод рождения: " << b.year;
}
void show(student s)
{
    cout << "\n\nСтудент:" << endl;
    cout << "\nИмя: " << s.name;
    cout << "\nДень рождения: " << s.date.day;
    cout << "\nМесяц рождения: " << s.date.month;
    cout << "\nГод рождения: " << s.date.year;
}

grandFather setGrandPa(int age_, string name_)
{
    grandFather grandPa = { age_, name_ };
    return grandPa;
}
birthDate setBirthDay(int day_, int month_, int year_)
{
    birthDate birthDay = { day_, month_, year_ };
    return birthDay;
}
date_ setDate(int day_, int month_, int year_, int num_, int num_month_, string name_)
{
    date_ date = { day_, month_, year_, num_, num_month_, name_ };
    return date;
}
student setStudent(int day_, int month_, int year_, string name_)
{
    student student = { day_, month_, year_, name_ };
    return student;
}
student setStudent(birthDate birthDay_, string name_)
{
    student student = {birthDay_.day, birthDay_.month, birthDay_.year, name_};
    return student;
}

int main()
{
    setlocale(LC_ALL, "");

    //int day_ba = 11;
    //int month_ba = 12;
    //int year_ba = 2009;
    //cout << "Бочаров Артём: " << day_ba << "." << month_ba << "." << year_ba << endl;

    //int day_dn = 21;
    //int month_dn = 07;
    //int year_dn = 2008;
    //cout << "Дымочкина Настя: " << day_dn << "." << month_dn << "." << year_dn << endl;

    //int day_li = 30;
    //int month_li = 07;
    //int year_li = 2009;
    //cout << "Лобозев Илья: " << day_li << "." << month_li << "." << year_li << endl;

    //int day_ge = 06;
    //int month_ge = 05;
    //int year_ge = 2009;
    //cout << "Газарян Эдуард: " << day_ge << "." << month_ge << "." << year_ge << endl;
   
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
        show(mass[i]);
    }

    date_ today = { 25,9,25,4,9,"Четверг"};
    cout << "День: " << today.day << "\nМесяц: " << today.month << "\nГод: " << today.year << "\nНомер дня: " << today.number << "\nНазвание дня: " << today.name << endl;

    grandFather grandFa = { 69, "Иван Иваныч" };

    show(grandFa);
    show(today);
    show(name_GE);
    show(GE);

    cout << endl << endl;
    cout << "=================================================================================" << endl;

    grandFather gF = setGrandPa(68, "Пётр Петрович");
    birthDate bD = setBirthDay(5, 6, 2007);
    date_ date = setDate(25, 9, 2025, 4, 9, "четверг");
    student stud1 = setStudent(7, 8, 2009, "Макар Сидоров");
    student stud2 = setStudent(bD, "Сидор Макаров");

    show(gF);
    show(bD);
    show(date);
    show(stud1);
    show(stud2);

    cout << "=================================================================================" << endl;

    int a;
    char c;
    double d;
    int* p;
    cout << "sizeof(a) = " << sizeof(a) << endl;
    cout << "sizeof(c) = " << sizeof(c) << endl;
    cout << "sizeof(d) = " << sizeof(d) << endl;
    cout << "sizeof(p) = " << sizeof(p) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(int*) = " << sizeof(int*) << endl;
    cout << "=================================================================================" << endl;

    test test = { '&', 123456 };
    cout << "sizeof(test) = " << sizeof(test) << endl;
    cout << "sizeof(grandFather) = " << sizeof(grandFa) << endl;
    cout << "sizeof(birthDay) = " << sizeof(BA) << endl;
    cout << "sizeof(student) = " << sizeof(name_AD) << endl;
    cout << "sizeof(data_) = " << sizeof(today) << endl;

    return 0;
}
