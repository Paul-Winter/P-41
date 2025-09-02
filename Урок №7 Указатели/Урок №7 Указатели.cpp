// Урок №7 Указатели.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int x = 123;
int y = 456;

void increment(int num)
{
    num++;
    cout << "inside func num = " << num << endl;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "inside swap a = " << a << endl;
    cout << "inside swap b = " << b << endl;
}

void printArr(int* pt,const int  SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout  << *(pt + i) << " ";
    }
    cout << endl;
}
void swapArr(int* pt, const int SIZE)
{   for (int i = 0; i < SIZE; i++)
    {
        if (i % 2 == 0)
        {
 
            swap(*(pt + i), *(pt + i + 1));

        }
    }
}

void showArr(int* pt1, int* pt2, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << *(pt1+i)<<"\t";
        cout << *(pt2 + i)<<endl;
    }
    cout << endl;
}
void showArr(int* pt1, int* pt2, const int SIZE1, const int SIZE2)
{
    cout << "общие элементы" << endl;
    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            if (*(pt1 + i) == *(pt2 + j))
                cout << *(pt1 + i) << "\t";
        }

    }
    cout << endl;
}
int main()
{
    setlocale(LC_ALL, "");
    const int SIZE = 5;

    int  array[SIZE] = { 1,2,6,9,5 };
    int array2[SIZE] = { 6,3,8,5,0 };

    int* pointerPt1 = &array[0];
    int* pointerPt2 = &array2[0];
    showArr(pointerPt1, pointerPt2, SIZE,SIZE);

    int* pointerX = &x;
    cout << "pointerX = " << pointerX << endl;
    int* pointerY = &y;
    cout << "pointerY = " << pointerY << endl;
    int* pointerZ = nullptr;
    cout << "pointerZ = " << pointerZ << endl;
    int* pt = &array[0];
    const int size = 6;
    int arr[size] = { 11, 21, 42, 35, 84, 79 };
    int* ptr = &arr[0];

    printArr(ptr, size);
    swapArr(ptr, size);
    printArr(ptr, size);
    printArr(&array[0], SIZE);

    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << "\t";
        cout << "*arr[] = " << *(ptr + i) << endl;
    }
   
    cout << "x = " << x << endl;
    increment(x);
    cout << "increment(x) = ";
    cout << x << endl;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    swap(&x, &y);
    cout << "swap(x, y)" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

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
