#include <iostream>
#include <cstdarg>

using namespace std;

int y = 0;

//float SomeFunc(int x, float y)
//{
//    cout << "1 ver" << endl;
//    return x + y;
//}
//float SomeFunc(float x, int y)
//{
//    cout << "2 ver" << endl;
//    return x + y;
//}
//template <typename T1, typename T2> T2 SomeFunc(T1 x, T2 y)
//{
//    return x + y;
//}
//int SomeFunc2(int x)
//{
//    cout << "x = " << ++x << endl;
//    return x;
//}
//double SomeFunc2(double x)
//{
//    return ++x;
//}

template <typename T, typename V> T SomeFunc(T x, V y)
{
    return x + y;
}
template <typename T> T SomeFunc2(T x)
{
    return ++x;
}

template <typename T> T summ(T a,T b)
{
    return a + b;
}
template <typename T> T sub(T a, T b)
{
    return a - b;
}
template <typename T> T mult(T a, T b)
{
    return a * b;
}
template <typename T> T divid(T a, T b)
{
    if (b == 0)
    {
        cout << "На ноль делить нельзя!" << endl;
        return a;
    }
    return a / b;
}
template <typename T> int modul(T a, T b)
{
    if (b == 0)
    {
        cout << "На ноль делить нельзя!" << endl;
        return (int)a;
    }
    return (int)a % (int)b;
}

template <typename T> T maximum(T r, T t)
{
    if (r < t)
    {
        return t;
    }
    return r;
}
template <typename T> T maximum(T r, T t, T f)
{
    if (r < t && t>f)
    {
        return t;
    }
    if (t < f && r < f)
    {
        return f;
    }
    return r;
}

template <typename T>T max_element(T length, T array[])
{

    T result = array[0];
    for (int i = 0; i < length; i++)
    {
        if (result < array[i])
            result = array[i];
    }
    return result;

}
template <typename I, typename D> D  max_element(I length, D array[])
{
    D result = array[0];
    for (int i = 0; i < length; i++)
    {
        if (result < array[i])
            result = array[i];
    }
    return result;
}
template <typename I> I max_element(I array[], I length)
{

    I result = array[0];
    for (int i = 0; i < length; i++)
    {
        if (result < array[i])
            result = array[i];
    }
    return result;

}
template <typename I, typename V> I max_element(I array[], V length) 
{
    V result = array[0];
    for (int i = 0; i < length; i++)
    {
        if (result < array[i])
            result = array[i];
    }
    return result;
}

template <typename T, typename D> D maximum2D(D array[][3],T row,T col)
{
    D result=array[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (result < array[i][j])
            {
                result = array[i][j];
                
            }
        }
    }
    return result;
}

//int add(int a, int b)
//{
//    return a + b;
//}
//
//int add(int a, int b, int c)
//{
//    return a + b + c;
//}
//
//int add(int a, int b, int c, int d)
//{
//    return a + b + c + d;
//}
//
//int add(int a, int b, int c, int d, int e)
//{
//    return a + b + c + d + e;
//}

int add(int numArgs, ...)
{
    int result = 0;
    va_list va;
    va_start(va, numArgs);

    for (int i = 0; i < numArgs - 1; i++)
    {
        result += va_arg(va, int);
    }

    va_end(va);
    return result;
}

/*
int summ(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mult(int a, int b)
{
    return a * b;
}
int divid(int a, int b)
{
    if (b == 0)
    {
        cout << "На ноль делить нельзя!" << endl;
        return a;
    }
    return a / b;
}
int modul(int a, int b)
{
    if (b == 0)
    {
        cout << "На ноль делить нельзя!" << endl;
        return a;
    }
    return a % b;
}

float summ(float a, float b)
{
    return a + b;
}
float sub(float a, float b)
{
    return a - b;
}
float mult(float a, float b)
{
    return a * b;
}
float divid(float a, float b)
{
    if (b == 0)
    {
        cout << "На ноль делить нельзя!" << endl;
        return a;
    }
    return a / b;
}
int modul(float a, float b)
{
    if (b == 0)
    {
        cout << "На ноль делить нельзя!" << endl;
        return a;
    }
    return (int)a % (int)b;
}

double summ(double a, double b)
{
    return a + b;
}
double sub(double a, double b)
{
    return a - b;
}
double mult(double a, double b)
{
    return a * b;
}
double divid(double a, double b)
{
    if (b == 0)
    {
        cout << "На ноль делить нельзя!" << endl;
        return a;
    }
    return a / b;
}
int modul(double a, double b)
{
    if (b == 0)
    {
        cout << "На ноль делить нельзя!" << endl;
        return a;
    }
    return (int)a % (int)b;
}
*/
//inline int max_element(int length, int array[])
//{
//    int result = array[0];
//    for (int i = 0; i < length; i++)
//    {
//        if (result < array[i])
//            result = array[i];
//    }
//    return result;
//}
//inline long max_element(int length, long array[])
//{
//    long result = array[0];
//    for (int i = 0; i < length; i++)
//    {
//        if (result < array[i])
//            result = array[i];
//    }
//    return result;
//}
//inline double max_element(int length, double array[])
//{
//    double result = array[0];
//    for (int i = 0; i < length; i++)
//    {
//        if (result < array[i])
//            result = array[i];
//    }
//    return result;
//}
//inline int max_element(int array[], int length)
//{
//    int result = array[0];
//    for (int i = 0; i < length; i++)
//    {
//        if (result < array[i])
//            result = array[i];
//    }
//    return result;
//}
/*int maximum(int r, int t)
{
    if (r < t)
    {
        return t;
    }
    return r ;
}
long maximum(long r, long t)
{

    if (r < t)
    {
        return t;
    }
    return r;
}
float maximum(float r, float t)
{
    if (r < t)
    {
        return t;
    }
    return r;
}
double maximum(double r, double t)
{

    if (r < t)
    {
        return t;
    }
    return r;
}*/
//double maximum(double r, double t, double f)
//{
//
//    if (r < t && t>f)
//    {
//        return t;
//    }
//    if (t< f && r<f )
//    {
//        return f;
//    }
//    return r;
//}

int main()
{
    setlocale(LC_ALL, "");

    int first = 0;
    int second = 0;
    int third = 0;
    int forth = 0;
    int fifth = 0;
    cout << "Введите первое число - ";
    cin >> first;
    cout << "Введите второе число - ";
    cin >> second;
    cout << "Введите третье число - ";
    cin >> third;
    cout << "Введите четвёртое число - ";
    cin >> forth;
    cout << "Введите пятое число - ";
    cin >> fifth;
    cout << "Сумма чисел равна: " << add(6, first, second, third, forth, fifth) << endl << endl;

    int array[][3]{ {1.9,2.1,3.2 }, { 4.6, 5.7, 6.5},{ 7.4, 8.5, 9.6} };

    cout << "максимальное число массива: " << maximum2D(array, 3, 3)<<endl;

    cout << "Вызов SomeFunc для целого числа 10 + 1.11: " << SomeFunc(10, 1.11) << endl;
    cout << "Вызов SomeFunc для целого числа 2.22 + 20: " << SomeFunc(2.22, 20) << endl;

    //cout << "Вызов SomeFunc2 для целого числа 10: " << SomeFunc2(10) << endl;
    //cout << "Вызов SomeFunc2 для вещественного числа 10.01: " << SomeFunc2(10.01) << endl;

    float a = 0, b = 0;
    cout << "Введите первое число - ";
    cin >> a;
    cout << "Введите второе число - ";
    cin >> b;
    cout << "Выберите действие\n1 - сумма\n2 - вычитание\n3 - умножение\n4 - деление\n5 - деление по модулю\nВыбор: ";
    int temp = 0;
    cin >> temp;
    switch (temp)
    {
        case 1:cout << summ(a, b); break;
        case 2:cout << sub(a, b); break;
        case 3:cout << mult(a, b); break;
        case 4:cout << divid(a, b); break;
        case 5:cout << modul(a, b); break;
    }
    cout << endl << endl;

    int num = 6;
    int x[]{ 10, 20, 30, 40, 50, 60 };
    long l[]{ 12L, 23L, 34L, 45L, 56L, 67L };
    double d[]{ 0.11, 0.22, 0.33, 0.44, 0.55, 0.66 };

    cout << "max element array int: " << max_element(x, num) << endl;
    cout << "max element array long: " << max_element(num, d) << endl;
    cout << "max element array double: " << max_element(num, x) << endl;
    
    cout << "для интенджера " << maximum(x[0], x[5]) << endl;
    cout << "для лонга " << maximum(l[1], l[4]) << endl;
    cout << "для флоута " << maximum(a, b) << endl;
    cout << "для дабл " << maximum(d[2], d[3]) << endl;

    cout << maximum(d[0], d[1], d[2]) << endl;

    return 0;
}

