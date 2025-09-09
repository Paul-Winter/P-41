#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    const char* c1 = "hello, world";
    const char* scr = "world";
    char chars[] = "hello";
    char* dest = &chars[0];

    // функции для работы со строками

    // возвращает значение символа, который пользователь набрал на клавиатуре
    cout << getchar() << endl;

    // выводит символ на экран
    cout << putchar('^') << endl;

    // выводит строку, заданную аргументом
    cout << puts(c1) << endl;

    // объединяет исходную строку и результирующую строку
    cout << strcat(dest, scr) << endl;



    return 0;
}
