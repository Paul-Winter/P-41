#include <iostream>
#include <string.h>

using namespace std;

class Human
{
private:
    string name;
    int age;

public:
    Human(string name, int age) : name {name}, age {age} {}
    Human() : Human("Иван Безымянный", 1) {}

    int GetAge()
    {
        return age;
    }
    void SetAge(int value)
    {
        if (value < 0)
        {
            age = 0;
        }
        else
        {
            age = value;
        }
    }

    string GetName()
    {
        return name;
    }
    void SetName(string value)
    {
        name = value;
    }

    //void Print()
    //{
    //    cout << name << " " << age << " лет" << endl;
    //}
};

class Student
{
private:
    string name;
    int group;
    string faculty;

public:
    // конструкторы
    Student(string Pname, int Pgroup, string Pfaculty)
        : name {Pname}, group {Pgroup}, faculty {Pfaculty} {}
    Student(string Pname) : Student(Pname, 0, "Неизвестный") {}
    Student(int Pgroup) : Student("Иван Безымянный", Pgroup, "Неизвестный") {}
    Student(string Pname, int Pgroup) : Student(Pname, Pgroup, "Неизвестный") {}
    Student(int Pgroup, string Pfaculty) :Student("Иван Безымянный", Pgroup, Pfaculty) {}
    Student(string Pname, string Pfaculty) :Student(Pname, 0, Pfaculty) {}
    Student() : Student("Иван Безымянный", 0, "Неизвестный") {}

    // методы получения значений
    string GetName()
    {
        return name;
    }
    int GetGroup()
    {
        return group;
    }
    string GetFaculty()
    {
        return faculty;
    }

    // методы для изменения
    void SetName(string Pname)
    {
        name = Pname;
    }
    void SetGroup(int Pgroup)
    {
        group = Pgroup;
    }
    void SetFaculty(string Pfaculty)
    {
        faculty = Pfaculty;
    }

    // метод вывода информации
    //void Print()
    //{
    //    cout << "Студент " << name << " из группы №" << group << endl;
    //    cout << "учится на факультете " << faculty << endl;
    //}
};

void Print(Human human)
{
    cout << human.GetName() << endl;
    cout << human.GetAge() << endl;
}

void Print(Student student)
{
    cout << student.GetName() << endl;
    cout << student.GetGroup() << endl;
    cout << student.GetFaculty() << endl;
}

int Sum(int a, int b)
{
    return a + b;
}
double Sum(double a, double b)
{
    return a + b;
}
int Sum(int a, int b, int c)
{
    return a + b + c;
}
double Sum(int a, double b)
{
    return a + b;
}
//void Sum(int x)
//{
//    cout << "x = " << x << endl;
//}

int main()
{
    setlocale(LC_ALL, "");

    Human baby;
    //baby.Print();
    Print(baby);

    //student.name = "Иванов Иван Иванович";
    //student.age = 17;
    //cout << "Студент " << student.name << endl;
    //cout << "Возраст " << student.age << endl;

    Human student{ "Петров Пётр Петрович", 17 };
    //student.Print();
    Print(student);

    baby.SetAge(0);
    cout << "Возраст младенца изменён на " << baby.GetAge() << " годиков" << endl;
    
    baby.SetName("Иванов Иван Иванович");
    cout << "Личность младенца установлена, это - " << baby.GetName() << endl;

    Student Anastasiya{"Дымочкина Анастасия Владимировна", 41, "Разработка ПО"};
    //Anastasiya.Print();
    Print(Anastasiya);

    int x = 12;
    int y = 25;
    cout << "x + y = " << Sum(x, y) << endl;

    double xd = 12.12;
    double yd = 25.25;
    cout << "xd + yd = " << Sum(xd, yd) << endl;

    int xi = 12;
    int yi = 13;
    int zi = 14;
    cout << "xi + yi + zi = " << Sum(xi, yi, zi) << endl;

    cout << "x + xd = " << Sum(x, xd) << endl;
    //Sum(x);

    Student Lobozev{ "Лобозев Илья Сергеевич",41,"Разработка ПО" };
    Student Sereda{ "Середа Роман Дмитриевич"};
    Student Suxota{ 41 };
    Student Gazaryan{"Газарян Эдуард Захарович","Разработка ПО" };
    Student Bocharov{ 41,"Разработка ПО"};
    Student Trechetkin{"Трещеткин Денис Евгеньевич",41};
    Student Madina{ "Мадина Тахировна",41,"Разработка ПО"};

    Bocharov.SetName("Бочаров Артём Романович");
    Gazaryan.SetGroup(41);

    Student group[]{Anastasiya,Lobozev,Sereda,Suxota,Gazaryan,Bocharov,Trechetkin,Madina};

    cout << "Студенты группы П-41:" << endl << endl;
    for (int i = 0; i < 8; i++)
    {
        Print(group[i]);
    }

    return 0;
}
