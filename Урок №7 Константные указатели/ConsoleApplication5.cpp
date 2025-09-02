// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int increment(int* x)
{
    //x = x + 1;
    //x += 1;
    return ++ * x;
}

int main()
{
    int name = 1234;
    cout << "int name = " << name << endl;
    int* address = &name;
    cout << "int* address = " << address << endl;
    cout << "value from address = " << *address << endl;

    const int x = 42;
    cout << "const int x = " << x << endl;

    // указатель на константу
    const int* pointer = &x;
    cout << "const int* pointer x = " << pointer << endl;
    cout << "value from pointer = " << *pointer << endl;
    // можно изменить адрес
    pointer = &name;
    cout << "const int* pointer name = " << pointer << endl;
    pointer = &x;
    cout << "const int* pointer x = " << pointer << endl;
    // невозможно изменить значение
    //*pointer = 12;

    // константный указатель
    int* const ptr = &name;
    cout << "int* const ptr = " << ptr << endl;
    int y = 13;
    // невозможно изменить адрес
    //ptr = &y;
    // можно изменить значение
    *ptr = 2345;

    // константный указатель на константу
    const int* const constPtr = &name;
    cout << "const int* const constPtr = " << constPtr << endl;
    cout << "value from constPtr = " << *constPtr << endl;
    // невозможно изменить значение
    //*constPtr = 3456;
    // невозможно изменить адрес
    //*constPtr = &x;

    cout << "increment(name) = " << increment(&name) << endl;
    cout << "int name = " << name << endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
