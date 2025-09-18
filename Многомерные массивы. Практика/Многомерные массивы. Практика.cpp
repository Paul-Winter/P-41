#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

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

    for (int i = 0; i < rowsA; i++)
    {
        cout << "Введите кол-во столбцов массива А: ";
        cin >> colsA;
    }
    for (int i = 0; i < rowsB; i++)
    {
        cout << "Введите кол-во столбцов массива B: ";
        cin >> colsB;
    }
    for (int i = 0; i < rowsC; i++)
    {
        cout << "Введите кол-во столбцов массива C: ";
        cin >> colsC;
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            A[i][j] = rand() % 9;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            B[i][j] = rand() % 9;
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < rowsC; i++)
    {
        for (int j = 0; j < colsC; j++)
        {
            C[i][j] = rand() % 9;
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
