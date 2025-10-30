#include <iostream>
#include <conio.h>

using namespace std;

class Student
{
public:
    // ФИО
    char name[30];
    // оценки
    int marks[5];
    // средний балл
    double getAver()
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += marks[i];
        }
        return sum / 5;
    }
    // показать все оценки

};
struct Stud
{
    // ФИО
    char name[30];
    // оценки
    int marks[5];
};

class AccessLevels
{
    int privateByDefault = 1;
public:
    int publicMember = 2;
protected:
    int protectedMember = 3;
private:
    int privateMember = 4;

public:
    void Print()
    {
        cout << "Private by default: " << privateByDefault << endl;
        cout << "Public member: " << publicMember << endl;
        cout << "Protected member: " << protectedMember << endl;
        cout << "Private member: " << privateMember << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    //Stud studStruct;
    Student studClass;

    strcpy_s(studClass.name, 20, "Иванов И.И.");
    //strcpy_s(studStruct.name, 20, "Петров П.П.");
    
    //studStruct.marks[0] = 1;
    studClass.marks[0] = 11;
    studClass.marks[1] = 10;
    studClass.marks[2] = 12;
    studClass.marks[3] = 9;
    studClass.marks[4] = 9;

    //cout << "Студент структуры: " << studStruct.name << " оценка: " << studStruct.marks[0] << endl;
    //cout << "Студент класса: " << studClass.name << " оценка: " << studClass.marks[0] << endl;

    //AccessLevels al;
    //al.Print();
    //al.publicMember = 13;
    //al.Print();

    cout << "Студент: " << studClass.name << endl;
    cout << "Средний балл: " << studClass.getAver() << endl;

    return 0;
}
