#pragma once
#include <iostream>

class Student
{
private:
    // ФИО
    char name[30];
    // оценки
    int marks[5];

public:
    // конструктор по умолчанию
    Student()
    {
        setName("Иван Безымянный");
        for (int i = 0; i < 5; i++)
        {
            marks[i] = 1;
        }
    }
    // конструктор параметризованный
    Student(const char* studentName)
    {
        setName(studentName);
        for (int i = 0; i < 5; i++)
        {
            marks[i] = 1;
        }
    }
    //~Student()
    //{
    //    if (name != nullptr)
    //    {
    //        delete[] name;
    //    }
    //    if (marks != nullptr)
    //    {
    //        delete[] marks;
    //    }
    //    std::cout << "сработал деструктор" << std::endl;
    //}
    // get-функция, аксессор, инспектор
    const char* getName()
    {
        return name;
    }
    // set-функция, мутатор
    void setName(const char* studentName)
    {
        strcpy_s(name, 30, studentName);
    }
    int getMark(int index)
    {
        return marks[index];
    }
    void setMark(int mark, int index)
    {
        if (mark < 1 || mark > 12)
        {
            mark = 1;
        }
        marks[index] = mark;
    }

    // средний балл
    double getAver();
    // показать все оценки
    void allMarks();
};
