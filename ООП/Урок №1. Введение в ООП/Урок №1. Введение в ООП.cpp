#include <iostream>
#include <conio.h>
#include "Student.h"

using namespace std;

struct Stud
{
public:
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
    //Student studClass;

    //studClass.setName("Иванов П.П.");

    ////strcpy_s(studClass.name, 20, "Иванов И.И.");
    ////strcpy_s(studStruct.name, 20, "Петров П.П.");
    //
    ////studStruct.marks[0] = 1;
    ////studClass.marks[0] = 11;
    ////studClass.marks[1] = 10;
    ////studClass.marks[2] = 12;
    ////studClass.marks[3] = 9;
    ////studClass.marks[4] = 9;

    //studClass.setMark(11, 0);
    //studClass.setMark(10, 1);
    //studClass.setMark(12, 2);
    //studClass.setMark(9, 3);
    //studClass.setMark(9, 4);

    ////cout << "Студент структуры: " << studStruct.name << " оценка: " << studStruct.marks[0] << endl;
    ////cout << "Студент класса: " << studClass.name << " оценка: " << studClass.marks[0] << endl;

    ////AccessLevels al;
    ////al.Print();
    ////al.publicMember = 13;
    ////al.Print();

    //cout << "Студент: " << studClass.getName() << endl;
    //studClass.allMarks();
    //cout << "Средний балл: " << studClass.getAver() << endl;

    //cout << endl << "______________________________________________" << endl << endl;

    //Student stud;
    //stud.setName("Петров И.И.");

    ////strcpy_s(stud.name, 20, "sdfagaregre");
    ////stud.marks[0] = 12;
    ////stud.marks[1] = 12;
    ////stud.marks[2] = 12;
    ////stud.marks[3] = 12;
    ////stud.marks[4] = 12;
    //stud.setMark(9, 0);
    //stud.setMark(10, 1);
    //stud.setMark(10, 2);
    //stud.setMark(11, 3);
    //stud.setMark(9, 4);

    //cout << "Студент: " << stud.getName() << endl;
    //stud.allMarks();
    //cout << "Средний балл: " << stud.getAver() << endl;

    cout << endl << "______________________________________________" << endl << endl;

    Student stud;
    cout << stud.getName() << endl;
    stud.allMarks();
    cout << "Средний балл: " << stud.getAver() << endl;       


    //cout << endl << "______________________________________________" << endl << endl;

    //Student stud3("Сидоров А.Б.");
    //cout << stud3.getName() << endl;
    //stud3.allMarks();
    //cout << "Средний балл: " << stud3.getAver() << endl;

    return 0;
}
