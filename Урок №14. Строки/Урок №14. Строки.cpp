#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    const int size = 6;
    
    // инициализация строкового массива №1
    char line1[size] = { 'C', 'O', 'D', 'E', '!', '\0' };

    cout << "Слово: ";
    for (int i = 0; i < size; i++)
    {
        cout << line1[i];
    }

    cout << "\n";

    // инициализация строкового массива №2
    char line2[] = "Coder!";
    cout << line2;

    return 0;
}
