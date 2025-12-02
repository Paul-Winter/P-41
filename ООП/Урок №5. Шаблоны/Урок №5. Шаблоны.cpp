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

int main()
{
    setlocale(LC_ALL, "");

    int a = 3;
    int b = 4;
    double c = 5.6;
    double d = 7.8;

    cout << "int + int = " << Sum(a, b) << endl;
    cout << "int + double = " << Sum(a, d) << endl;
    cout << "double + int = " << Sum(c, b) << endl;
    cout << "double + double = " << Sum(c, d) << endl;

    return 0;
}
