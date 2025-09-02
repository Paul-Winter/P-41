// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void swap(int* x, int* y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

int main()
{
    srand(time(NULL));
    int x = 42;
    int y = 13;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    swap(&x, &y);
    cout << endl << "swap(x, y)" << endl << endl;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    const int size = 5;
    int arr[size] = { 12, 33, 44, 7, 81 };

    int* ptr = &arr[0];
    cout << "*ptr = " << *ptr << endl;
    cout << "*ptr + 1 = " << *ptr + 1 << endl;
    cout << "ptr = ptr + 1" << endl;
    ptr = ptr + 1;
    cout << "*ptr = " << *ptr << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }
    cout << endl;
    int* ptr1 = &arr[0];
    for (int i = 0; i < size; i++)
    {
        cout << *ptr1 << " ";
        ptr1=ptr1+1;
    }
    int* ptr2 = &arr[0];
    *(ptr2 + 2) = 55;
    *(ptr2 + 2) = 55;
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *ptr2 << " ";
        ptr2 = ptr2 + 1;
    }
    for (int i = 0; i < size; i++)
    {
        if (i >= size - 2)
            swap(ptr2, ptr2 + size - 1);
        else
            swap(ptr2 + i, ptr2 + i + 2); 
    }
    for (int i = 0; i < size; i++)
    {
        cout << *ptr2 << " ";
        ptr2 = ptr2 + 1;
    }
    int mass[10]{ 0 };
    for (int i = 0; i < 10; i++)
    {
        mass[i] = rand() % 99;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << mass[i] << " ";
    }
    for (int i = 0; i < 10; i+=2)
    {
        swap(mass[i], mass[i + 1]);
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << mass[i] << " ";
    }
    return 0;
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
