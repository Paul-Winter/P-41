#include <iostream>
#include <time.h>

using namespace std;

class Fraction
{
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom) : numerator{num}, denominator{denom}
    {
        cout << "Дробь: " << this << " создана" << endl;
    }
    Fraction() : Fraction(1, 1) {}
    Fraction(const Fraction& fract)
        : numerator{fract.numerator}, denominator{fract.denominator}
    {
        cout << "Дробь: " << this << " скопирована" << endl;
    }
    ~Fraction()
    {
        cout << "Дробь: " << this << " удалена" << endl;
    }
    void print()
    {
        cout << "(" << numerator << " / " << denominator << ")" << endl;
    }
};

class DynArray
{
    int* arr;
    int size;
public:
    DynArray(int size) : arr{new int[size]}, size{size}
    {
        cout << "Создан дин. массив из: " << size << " эл-в: " << this << endl;
    }
    DynArray() : DynArray(5) {}
    DynArray(const DynArray& object) : arr{new int[object.size]}, size{object.size}
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = object.arr[i];
        }
        cout << "Скопирован дин. массив из: " << size << " эл-в: " << this << endl;
    }
    ~DynArray()
    {
        cout << "Попытка освободить память " << arr << " указателя" << endl;
        delete[] arr;
        cout << "Удалён дин. массив из: " << size << " эл-в: " << this << endl;
    }
    int getElem(int index) { return arr[index]; }
    void setElem(int value, int index) { arr[index] = value; }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void randomize()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 10;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    /*
    Fraction frac1{ 2,3 };
    Fraction frac2{ frac1 };

    cout << "frac1 = ";
    frac1.print();

    cout << "frac2 = ";
    frac2.print();

    Fraction frac3{ Fraction{3,4} };
    cout << "frac3 = ";
    frac3.print();

    cout << endl;
    */

    DynArray arr1{ 10 };
    arr1.randomize();
    cout << "arr1 elements: ";
    arr1.print();

    DynArray arr2{ arr1 };
    cout << "arr2 elements: ";
    arr2.print();

    return 0;
}
