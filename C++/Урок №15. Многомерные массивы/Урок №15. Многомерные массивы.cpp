#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    //// количество строк
    //int rows = 5;
    //// количество столбцов
    //int cols = 5;

    int rows, cols;
    cout << "Сколько строк? ";
    cin >> rows;

    // двумерный динамический массив
    int** pArr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        cout << "Сколько столбцов? ";
        cin >> cols;
        pArr[i] = new int[cols];

        for (int j = 0; j < cols; j++)
        {
            cout << "Введите оценку: ";
            cin >> pArr[i][j];
        }
        cout << endl;
    }

    //pArr[2][2] = 1234;
    //cout << pArr[2][2] << endl;

    // удаление двумерного массива
    for (int i = 0; i < rows; i++)
    {
        delete[] pArr[i];
    }
    delete[] pArr;

    return 0;
}
