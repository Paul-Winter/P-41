#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    //std::cout << "Привет, Мир!" << std::endl;
    //int a;
    //std::cin >> a;
    //std::cerr
    //std::clog

    const int MAX_LEN_PATH = 250;
    const int MAX_COLS = 15;
    const int MAX_ROWS = 20;

    char path[MAX_LEN_PATH];
    cout << "Пожалуйста, введите путь к файлу:\t";
    cin.getline(path, MAX_LEN_PATH);

    int count = 0;
    int i = 0;
    int j = 0;

    char text[MAX_COLS];

    // открытие файла в двоичном режиме
    ifstream input(path, ios::in | ios::binary);

    if (!input)
    {
        cout << "Невозможно открыть файл!" << endl;
        return 1;
    }

    cout.setf(ios::uppercase);

    while (!input.eof())
    {
        // посимвольное чтение
        for (i = 0; i < MAX_COLS && !input.eof(); i++)
        {
            input.get(text[i]);
        }

        if (i < MAX_COLS)
        {
            i--;
        }

        for (; j < i; j++)
        {
            cout << text[i];
        }

        for (;j < MAX_COLS; j++)
        {
            cout << "        ";
        }
        cout << "\t";

        if (++count == MAX_ROWS)
        {
            count = 0;
            cout << "Пожалуйста, нажмите любую клавишу...";
            char s;
            cin >> s;
        }
        // закрываем файл
        input.close();
    }

    return 0;
}
