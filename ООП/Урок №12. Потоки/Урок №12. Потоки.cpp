#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void readFileCppStyle()
{
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
        return;
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

        for (; j < MAX_COLS; j++)
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
}

class Human
{
    int age;
    char* name;
    char* surname;

public:
    Human(char* n, char* s, int a)
    {
        name = new char[strlen(n) + 1];
        if (!name)
        {
            cout << "Ошибка при выделении памяти!" << endl;
            exit(1);
        }
        strcpy(name, n);

        surname = new char[strlen(s) + 1];
        if (!surname)
        {
            cout << "Ошибка при выделении памяти!" << endl;
            exit(1);
        }
        strcpy(surname, s);

        age = a;
    }
    Human()
    {
        name = 0;
        surname = 0;
        age = 0;
    }
    ~Human()
    {
        delete[] name;
        delete[] surname;
    }
    void Put()
    {
        char temp[1024];

        cout << "Введите имя:\t";
        cin >> temp;
        if (name)
        {
            delete[] name;
        }
        name = new char[strlen(temp) + 1];
        if (!name)
        {
            cout << "Ошибка при выделении памяти!" << endl;
            exit(1);
        }
        strcpy(name, temp);

        cout << "Введите фамилию:\t";
        cin >> temp;
        if (surname)
        {
            delete[] surname;
        }
        surname = new char[strlen(temp) + 1];
        if (!name)
        {
            cout << "Ошибка при выделении памяти!" << endl;
            exit(1);
        }
        strcpy(surname, temp);

        cout << "Введите возраст:\t";
        cin >> age;
    }
    void Show()
    {
        cout << "\nИмя:\t" << name;
        cout << "\nФамилия:\t" << surname;
        cout << "\nВозраст:\t" << age << endl;
    }
    void SaveToFile()
    {
        int size;
        fstream file("human.txt", ios::out | ios::binary | ios::app);
        if (!file)
        {
            cout << "Файл не открылся для записи!" << endl;
            exit(2);
        }

        // запись возраста
        file.write((char*)&age, sizeof(age));

        // запись имени
        size = strlen(name);
        file.write((char*)&size, sizeof(int));
        file.write((char*)name, size * sizeof(char));

        // запись фамилии
        size = strlen(surname);
        file.write((char*)&size, sizeof(int));
        file.write((char*)surname, size * sizeof(char));

        file.close();
    }
    void ShowFromFile()
    {
        fstream file("human.txt", ios::in | ios::binary);
        if (!file)
        {
            cout << "Файл не открылся для чтения!" << endl;
            exit(2);
        }
        char* n;
        char* s;
        int a;
        int temp;

        while (file.read((char*)&a, sizeof(int)))
        {
            cout << "\nИмя:\t";
            file.read((char*)&temp, sizeof(int));
            n = new char[temp + 1];
            if (!n)
            {
                cout << "Ошибка при выделении памяти!" << endl;
                exit(1);
            }
            file.read((char*)n, temp * sizeof(char));
            n[temp] = '\0';
            cout << n;

            cout << "\nФамилия:\t";
            file.read((char*)&temp, sizeof(int));
            s = new char[temp + 1];
            if (!s)
            {
                cout << "Ошибка при выделении памяти!" << endl;
                exit(1);
            }
            file.read((char*)s, temp * sizeof(char));
            s[temp] = '\0';
            cout << s;

            cout << "\nВозраст:\t" << a << endl;
            delete[]n;
            delete[]s;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "");

    //std::cout << "Привет, Мир!" << std::endl;
    //int a;
    //std::cin >> a;
    //std::cerr
    //std::clog

    //readFileCppStyle();

    Human* man;
    do
    {
        cout << "\nВведите 1 для добавления нового человека в файл\n";
        cout << "Введите 2 для показа всех людей в файле\n";
        cout << "Введите 3 для выхода из программы\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1: man = new Human;
                man->Put();
                man->SaveToFile();
                delete man;
                break;
        case 2: man = new Human;
                man->ShowFromFile();
                delete man;
                break;
        case 3: cout << "До свидания!" << endl;
                return 0;
        default:
                cout << "Неверный ввод!" << endl;
        }
    } while (1);

    return 0;
}
