#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    // создаём массивы
    int rowsA, colsA;
    cout << "Введите кол-во строк массива А: ";
    cin >> rowsA;

    int rowsB, colsB;
    cout << "Введите кол-во строк массива B: ";
    cin >> rowsB;

    int rowsC, colsC;
    cout << "Введите кол-во строк массива C: ";
    cin >> rowsC;

    int** A = new int* [rowsA];
    int** B = new int* [rowsB];
    int** C = new int* [rowsC];

    // заполняем массивы случайными значениями от 0 до 9
    for (int i = 0; i < rowsA; i++)
    {
        cout << "Введите кол-во столбцов массива А: ";
        cin >> colsA;
        A[i] = new int[colsA];
        for (int j = 0; j < colsA; j++)
        {
            A[i][j] = rand() % 10;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rowsB; i++)
    {
        cout << "Введите кол-во столбцов массива B: ";
        cin >> colsB;
        B[i] = new int[colsB];
        for (int j = 0; j < colsB; j++)
        {
            B[i][j] = rand() % 10;
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rowsC; i++)
    {
        cout << "Введите кол-во столбцов массива C: ";
        cin >> colsC;
        C[i] = new int[colsC];
        for (int j = 0; j < colsC; j++)
        {
            C[i][j] = rand() % 10;
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
