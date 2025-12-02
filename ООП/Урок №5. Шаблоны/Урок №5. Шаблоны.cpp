#include <iostream>

using namespace std;

//int Sum(int x, int y)
//{
//    return x + y;
//}
//int Sum(int x, double y)
//{
//    return x + y;
//}
//double Sum(double x, int y)
//{
//    return x + y;
//}
//double Sum(double x, double y)
//{
//    return x + y;
//}

//int Sub(int x, int y)
//{
//    return x - y;
//}
//double Sub(double x, int y)
//{
//    return x - y;
//}
//double Sub(double x, double y)
//{
//    return x - y;
//}
//double Sub(double x, float y)
//{
//    return x - y;
//}

//int Mult(int x, int y)
//{
//    return x * y;
//}
//double Mult(double x, int y)
//{
//    return x * y;
//}
//double Mult(double x, double y)
//{
//    return x * y;
//}
//double Mult(double x, float y)
//{
//    return x * y;
//}

//int Div(int x, int y)
//{
//    return x / y;
//}
//double Div(double x, int y)
//{
//    return x / y;
//}
//double Div(double x, double y)
//{
//    return x / y;
//}
//double Div(double x, float y)
//{
//    return x / y;
//}

template<class T>
T Div(T parameter1, T parameter2)
{
    return parameter1 * parameter2;
}
template<class T1, class T2>
T1 Div(T1 parameter1, T2 parameter2)
{
    return parameter1 / parameter2;
}
//template<class M1, class M2>
//M2 Div(M2 parameter1, M1 parameter2)
//{
//    return parameter1 / parameter2;
//}

template<class T>
T Mult(T parameter1, T parameter2)
{
    return parameter1 * parameter2;
}
template<class T1,class T2>
T1 Mult(T1 parameter1, T2 parameter2)
{
    return parameter1 * parameter2;
}
template<class T>
T Sub(T parameter1, T parameter2)
{
    return parameter1 - parameter2;
}
template<class T1, class T2>
T1 Sub(T1 parameter1, T2 parameter2)
{
    return parameter1 - parameter2;
}
template<class T>
T Sum(T parameter1, T parameter2)
{
    return parameter1 + parameter2;
}
template<class T1, class T2>
T1 Sum(T1 parameter1, T2 parameter2)
{
    return parameter1 + parameter2;
}

//template<class T1, class T2>
//T2 Sum(T1 parameter1, T2 parameter2)
//{
//    return parameter1 + parameter2;
//}

//int Mod(int par1, int par2)
//{
//    return par1 % par2;
//}

int Mod(double par1, double par2)
{
    return int(par1) % int(par2);
}
int Mod(float par1, double par2)
{
    return int(par1) % int(par2);
}
int Mod(double par1, float par2)
{
    return int(par1) % int(par2);
}

//template<class I, class D, class F>
//I Mod(D par1, F par2)
//{
//    return I(par1) % I(par2);
//}
//template<class I, class D, class F>
//I Mod(F par1, D par2)
//{
//    return I(par1) % I(par2);
//}

template<class T>
T Mod(T parameter1, T parameter2)
{
    return parameter1 % parameter2;
}

//template<class T>
//int Mod(T parameter1, T parameter2)
//{
//    return int (parameter1) % int (parameter2);
//}
//void Print(int x)
//{
//    std::cout << x <<std::endl;
//}
//void Print(double x)
//{
//    std::cout << x << std::endl;
//}
//void Print(float x)
//{
//    std::cout << x << std::endl;
//}

template<class Z>
void Print(Z par)
{
    std::cout << par << std::endl;
}
int ZeroReturn()
{
    return 0;
}

template <class T>
class Point
{
    T x;
    T y;
};
//class Point1
//{
//    double x;
//    double y;
//};
//class Point2
//{
//    int x;
//    int y;
//};
//class Point3
//{
//    float x;
//    float y;
//};

template <class T>
class Fraction
{
    T numerator;
    T denominator;
};
//class Fraction1
//{
//    int numerator;
//    int denominator;
//};
//class Fraction2
//{
//    long numerator;
//    long denominator;
//};

template <class T>
class DynArray
{
    T* array;
    int size;
};

int main()
{
    setlocale(LC_ALL, "");

    int a = 3;
    int b = 4;
    double c = 5.6;
    double d = 7.8;
    float f = 9.9;

    cout << "int + int = " << Sum(a, b) << endl;
    cout << "int + double = " << Sum(a, d) << endl;
    cout << "double + int = " << Sum(c, b) << endl;
    cout << "double + double = " << Sum(c, d) << endl;
    cout << "_________________________________________" << endl;

    cout << "int - int = " << Sub(a, b) << endl;
    cout << "double - int = " << Sub(c, b) << endl;
    cout << "double - double = " << Sub(d, c) << endl;
    cout << "double - float = " << Sub(d, f) << endl;
    cout << "_________________________________________" << endl;

    cout << "int * int = " << Mult(a, b) << endl;
    cout << "double * int = " << Mult(c, b) << endl;
    cout << "double * double = " << Mult(d, c) << endl;
    cout << "double * float = " << Mult(d, f) << endl;
    cout << "_________________________________________" << endl;

    cout << "int / int = " << Div(a, b) << endl;
    cout << "double / int = " << Div(c, b) << endl;
    cout << "double / double = " << Div(d, c) << endl;
    cout << "double / float = " << Div(d, f) << endl;
    cout << "_________________________________________" << endl;

    cout << "int % int = " << Mod(a, b) << endl;
    cout << "double % double = " << Mod(d, c) << endl;
    cout << "double % float = " << Mod(d, f) << endl;
    cout << "float % double = " << Mod(f, d) << endl;
    cout << "_________________________________________" << endl;

    Print(127);
    Print(d);
    Print(f);

    return 0;
}
