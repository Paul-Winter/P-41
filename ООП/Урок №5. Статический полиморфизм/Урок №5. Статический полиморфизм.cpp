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

    void Print()
    {
        cout << name << " " << age << " лет" << endl;
    }
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
    void Print()
    {
        cout << "Студент " << name << " из группы №" << group << endl;
        cout << "учится на факультете " << faculty << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Human baby;
    baby.Print();

    //student.name = "Иванов Иван Иванович";
    //student.age = 17;
    //cout << "Студент " << student.name << endl;
    //cout << "Возраст " << student.age << endl;

    Human student{ "Петров Пётр Петрович", 17 };
    student.Print();

    baby.SetAge(0);
    cout << "Возраст младенца изменён на " << baby.GetAge() << " годиков" << endl;
    
    baby.SetName("Иванов Иван Иванович");
    cout << "Личность младенца установлена, это - " << baby.GetName() << endl;

    Student Anastasiya{"Дымочкина Анастасия Владимировна", 41, "Разработка ПО"};
    Anastasiya.Print();

    return 0;
}
