#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    setlocale(LC_ALL, "");

    int number = 12;    // копирующая инициализация
    int value(42);      // прямая инициализация
    int size{ 33 };     // унифицированная иницилизация

    cout << "number = " << number << endl;
    cout << "value = " << value << endl;
    cout << "size = " << size << endl;

    const float goodTemp{ 36.6 };
    int grades[4]{ 2,3,4,5 };
    int matrix[2][2]{ {1,2}, {3,4} };
    char* str{ new char[14] {"Hello, World!"} };
    int& ref{ size };
    Point point{ 10,-6 };

    return 0;
}
