#include <iostream>

using namespace std;

void swapPointers(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void swapRefs(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int* maxP(int *x, int *y)
{
    if (*x > *y)
        return x;
    return y;
}
int& maxR(int &x, int &y)
{
    if (x > y)
        return x;
    return y;
}

void chaslivay(int &x)
{
    x = 13;
}
void bolshe(int x[], int y)
{
    int max = x[0];
    int min = x[0];
    int maxT = 0;
    int minT = 0;
    for (int i = 0; i < y; i++)
    {
        if (max < x[i])
        {
            max = x[i];
            maxT = i;
        }
        if (min > x[i])
        {
            min = x[i];
            minT = i;
        }
    }
    swapRefs(x[minT], x[maxT]);
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    int v = 10100101;
    int arr1[100];
    for (int i = 0; i < 100; i++)
    {
        arr1[i] = rand() % 99;
        //cout << arr[i] << " ";
    }

    printArray(arr1, 100);
    cout << endl << endl;

    int arr2[200];
    for (int i = 0; i < 200; i++)
    {
        arr2[i] = rand() % 100 + 100;
        //cout << arr2[i] << " ";
    }

    cout << endl << endl;
    printArray(arr2, 200);
    cout << endl << endl;
            
    //int* ptr = &ars[0];

    //cout << endl << *ptr << endl;
    //for (int j = 0; j < 100; j++)
    //{
    //    cout << *(ptr + j) << " ";
    //}

    int x = 1234;
    int* ptrX = &x;
    int& refX = x;
    int* p = &refX;

    cout << "int x = " << x << endl;
    cout << "int* ptr = " << *ptrX << endl;
    cout << "int& ref = " << refX << endl;
    cout << "int* p = " << *p << endl;
    cout << endl << endl;

    int y = 2345;
    cout << "До вызова swapPointers:" << endl;
    cout << "x = " << x << "; y = " << y << endl;
    cout << "После вызова swapPointers, до вызова swapRefs:" << endl;
    swapPointers(&x, &y);
    cout << "x = " << x << "; y = " << y << endl;
    cout << "После вызова swapRefs:" << endl;
    swapRefs(x, y);
    cout << "x = " << x << "; y = " << y << endl;

    cout << "*x > *y ? " << *maxP(&x, &y) << endl;
    cout << "&x > &y ? " << maxR(x, y) << endl;

    cout << "v = " << v << endl;
    chaslivay(v);
    cout << "v = " << v << endl;

    int u[4]
    {
        1,2,3,4
    };

    for (int i = 0; i < 4; i++)
    {
        cout << u[i] << endl;
    }
    cout << endl;
    bolshe(u, 4);

    for (int i = 0; i < 4; i++)
    {
        cout << u[i] << endl;
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
