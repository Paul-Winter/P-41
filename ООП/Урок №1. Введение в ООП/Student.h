#pragma once
class Student
{
public:
    // ФИО
    char name[30];
    // оценки
    int marks[5];
    // средний балл
    double getAver();
    // показать все оценки
    void allMarks();
};
