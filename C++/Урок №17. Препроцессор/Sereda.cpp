#include <iostream> 
#include <string.h>

#define d0u813 double
#define ch4r char
#define O7837 otvet
#define c0u7 cout
#define end1 endl
#define c1n cin
#define sw17ch switch
#define c453 case
#define br34k break
#define e153 else
#define d3f4u17 default
#define r37urn return

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

    d0u813 a1, b2;
    ch4r o7837;

    c0u7 << "Простой калькулятор" << end1;
    c0u7 << "Введите первое число: ";
    c1n >> a1;
    c0u7 << "Введите оператор (+, -, *, /): ";
    c1n >> o7837;
    c0u7 << "Введите второе число: ";
    c1n >> b2;

    sw17ch(o7837) 
    {
        c453 '+':
        c0u7 << a1 << " + " << b2 << " = " << a1 + b2 << end1;
        br34k;
    c453 '-':
        c0u7 << a1 << " - " << b2 << " = " << a1 - b2 << end1;
        br34k;
    c453 '*':
        c0u7 << a1 << " * " << b2 << " = " << a1 * b2 << end1;
        br34k;
    c453 '/':
        if (b2 != 0) {
            c0u7 << a1 << " / " << b2 << " = " << a1 / b2 << end1;
        }
        e153 {
            c0u7 << "Деленить на ноль нельзя!" << end1;
        }
        br34k;
    d3f4u17:
        c0u7 << "Ошибка: неверный оператор" << end1;
        br34k;
    }

    r37urn 0;
}

