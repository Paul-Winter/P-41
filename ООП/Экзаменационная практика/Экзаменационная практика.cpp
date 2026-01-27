#include <iostream>

using namespace std;

void Hangman(int lost)
{
    if (lost == 0)
    {
        cout << "__________" << endl;
    }
    else if (lost == 1)
    {
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "_____|_____" << endl;
    }
    else if (lost == 2)
    {
        cout << "  ---|-" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "_____|_____" << endl;
    }
    else if (lost == 3)
    {
        cout << "  |--|-" << endl;
        cout << "  O  |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "_____|_____" << endl;
    }
    else if (lost == 4)
    {
        cout << "  |--|-" << endl;
        cout << "  0  |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "_____|_____" << endl;
    }
    else if (lost == 5)
    {
        cout << "  |--|-" << endl;
        cout << "  0  |" << endl;
        cout << "  |  |" << endl;
        cout << "     |" << endl;
        cout << "_____|_____" << endl;
    }
    else if (lost == 6)
    {
        cout << "  |--|-" << endl;
        cout << "  0  |" << endl;
        cout << " /|  |" << endl;
        cout << "     |" << endl;
        cout << "_____|_____" << endl;
    }
    else if (lost == 7)
    {
        cout << "  |--|-" << endl;
        cout << "  0  |" << endl;
        cout << " /|\\ |" << endl;
        cout << "     |" << endl;
        cout << "_____|_____" << endl;
    }
    else if (lost == 8)
    {
        cout << "  |--|-" << endl;
        cout << "  0  |" << endl;
        cout << " /|\\ |" << endl;
        cout << " /   |" << endl;
        cout << "_____|_____" << endl;
    }
    else if (lost == 9)
    {
        cout << "  |--|-" << endl;
        cout << "  0  |" << endl;
        cout << " /|\\ |" << endl;
        cout << " / \\ |" << endl;
        cout << "_____|_____" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "");

    for (int i = 0; i < 10; i++)
    {
        Hangman(i);
        cout << endl << endl;
    }

    return 0;
}
