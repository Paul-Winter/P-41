// Урок №7 Выделение памяти.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int* ptr(int* pointer, int size, int a)
{
    int* pointer2 = new int[size*2];
    for (int i = 0; i < size; i++)
    {
        *(pointer2 + i) = *(pointer + i);
    }
    *(pointer2 + size) = a;
    return pointer2;
}
void print(int* pointer, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *(pointer + i) << " ";
    }
    cout << endl;
}
int* ptr(int* pointer, int size)
{
    int even = 0;
    int odd = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(pointer + i) % 2 == 0)
            even++;
        else
            odd++;
    }
    int* t = new int[even];
    even = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(pointer + i) % 2 == 0)
        {
           * (t + even) = *(pointer + i);
           even++;
        }
    }
    print(t, even);
    return t;
}
void sort(int* pointer, int size)
{
    int pol=0, nol=0, negative=0;
    for (int i = 0; i < size; i++)
    {
        if (*(pointer + i) == 0)
            nol++;
        else if (*(pointer + i) > 0)
            pol++;
        else
            negative++;
    }
    int* pointernull = new int[nol];
    int* pointerplus = new int[pol];
    int* pointerneg = new int[negative];
    pol = 0;
    nol = 0;
    negative = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(pointer +i ) == 0)
        {
            *(pointernull + nol)= *(pointer + i);
            nol++;
        }
        else if (*(pointer + i) > 0)
        {
            *(pointerplus + pol) = *(pointer + i);
            pol++;
        }
        else
        {
            *(pointerneg + negative) = *(pointer + i);
            negative++;
        }
    }
    cout << "\n\n\nМассив положительных чисел: ";
    print(pointerplus, pol);
    cout << "\nМассив отрицательных чисел: ";
    print(pointerneg, negative);
    cout << "\nМассив из нулей: ";
    print(pointernull, nol);
}
int main()
{
    setlocale(LC_ALL, "");

    //srand(time(NULL));
    //cout << "Работать на большом экране будет студент: " << rand()%4 + 1 << endl;

    const int size = 10;
    int arr1[size];
    int arr2[11];

    int arrStatic[100];
    int arrSize;

    int arrDynSize;
    int *arrDynamic;
    /*cout << "Введите размер массива: ";
    cin >> arrDynSize;
    arrDynamic = new int[arrDynSize];
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < arrDynSize; i++)
    {
        //cout << " ";
        cin >> arrDynamic[i];
    }
    
    for (int i = 0; i < arrDynSize; i++)
    {
        cout << arrDynamic[i] << " ";
    }

    delete[] arrDynamic;

    const int massSize = 10;
    int mass[massSize]{1,2,3,4,5,6,7,8,9,10};
    int mass1[massSize + 1];
    for (int i = 0; i < massSize; i++)
    {
        mass1[i] = mass[i];
    }
    int elm = 11;
    mass1[massSize] = elm;
    for (int i = 0; i < massSize; i++)
    {
        cout << " " << mass[i];
    }
    for (int i = 0; i < massSize+1; i++)
    {
        cout << " " << mass1[i];
    }*/
    int sizer = 4, a=0;
    int* pointer;
    pointer = new int[sizer];
    for (int i = 0; i < sizer; i++)
    {
        cout << "Введите " << i+1 << " элемент массива: ";
        cin >> *(pointer + i);
    }
    cout << "Введите число, которое хотите добавить в массив: ";
    cin >> a;
    print(pointer, sizer);
    int* pointer2 = ptr(pointer, sizer, a);
    print(pointer2, sizer * 2);
    int mass[10]{ 5,-1,-6,0,3,0,-8,8,-5,0 };
    int* pointerst = &mass[0];
    ptr(pointerst, 10);
    print(pointerst, 10);
    sort(pointerst, 10);
  

    /*
    cout << "Введите размер массива (от 1 до 100): ";
    cin >> arrSize;
    if (arrSize > 100 || arrSize < 1)
        arrSize = 1;
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Введите значение " << i << " элемента: ";
        cin >> arrStatic[i];
        cout << endl;
    }
    cout << "Ваш массив: " << endl;
    for (int j = 0; j < arrSize; j++)
    {
        cout << arrStatic[j]<<" ";
    }
    cout << endl;
    */

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
