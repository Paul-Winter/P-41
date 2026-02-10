#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

// rename - переименовывает файл
// remove - удаляет файл
#include <stdio.h>

// поиск файлов
#include <io.h>

// mkdir - создаёт директорию
// rmdir - удаляет директорию
//! Важно!!! Удалить и переименовать можно только пустую директорию
#include <direct.h>

using namespace std;

struct Human
{
    // Имя:
    char name[255];
    // Возраст:
    int age;
};

void RenameFile()
{
    char oldName[50];
    char newName[50];

    cout << "\nВведите старое имя: ";
    cin >> oldName;
    cout << "\nВведите новое имя: ";
    cin >> newName;

    if (rename(oldName, newName) != 0)
    {
        cout << "\nERROR!!! Невозможно переимновать файл" << endl;
    }
    else
    {
        cout << "\nФайл успешно переименован!" << endl;
    }
}
void RemoveFile()
{
    char name[50];

    cout << "\nВведите имя файла: ";
    cin >> name;

    if (remove(name) != 0)
    {
        cout << "\nERROR!!! Невозможно удалить файл!" << endl;
    }
    else
    {
        cout << "\nФайл был успешно удалён!" << endl;
    }
}
void Dir()
{
    char path[100];
    char mask[15];
    
    cout << "\nВведите полный путь к файлу, например: C:\\\\: ";
    cin >> path;
    cout << "\nВведите маску файла, например: .txt: ";
    cin >> mask;

    strcat(path, mask);
    _finddata_t* fileinfo = new _finddata_t;
    long end = _findfirst(path, fileinfo);
    int work = end;
    int count = 0;
    while (work != -1)
    {
        count++;
        cout << fileinfo->name << endl;
        work = _findnext(end, fileinfo);
    }
    cout << "\nИнформация: найдено " << count << " файлов в папке " << path << endl;
    _findclose(end);
    delete fileinfo;
}

void RenameDir()
{
    char oldName[50];
    char newName[50];

    cout << "\nВведите старое имя: ";
    cin >> oldName;
    cout << "\n Введите новое имя: ";
    cin >> newName;

    if (rename(oldName, newName) != 0)
    {
        cout << "\nERROR!!! Невозможно переименовать папку!" << endl;
    }
    else
    {
        cout << "\nПапка успешно переименована!" << endl;
    }
}
void CreateDir()
{
    char name[50];

    cout << "\nВведите имя папки: ";
    cin >> name;

    if (_mkdir(name) != 0)
    {
        cout << "\nERROR!!! Невозможно создать папку!" << endl;
    }
    else
    {
        cout << "\nПапка " << name << " успешно создана!" << endl;
    }
}
void RemoveDir()
{
    char name[50];

    cout << "\nВведите имя папки: ";
    cin >> name;

    if (_rmdir(name) != 0)
    {
        cout << "\nERROR!!! Невозможно удалить папку!" << endl;
    }
    else
    {
        cout << "\nПапка была успешно удалена!" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "");

#pragma region Сохранение объектов в файл

    //// создаём объекты структуры (класса)
    //Human man;
    //Human man2;

    //cout << "\nВведите имя: ";
    //cin >> man.name;
    //cout << "\nВведите возраст: ";
    //cin >> man.age;

    //// открываем файл на запись
    //FILE* f = fopen("test.txt", "w+");
    //if (!f)
    //{
    //    exit(0);
    //}

    //// запись первого объекта в файл
    //fwrite(&man, sizeof(Human), 1, f);    
    //fclose(f);

    //// открываем файл на чтение
    //f = fopen("test.txt", "r+");
    //if (!f) exit(0);

    //// считывание содержимого файла в объект
    //fread(&man2, sizeof(Human), 1, f);
    //fclose(f);

    //cout << "считывание содержимого файла в объект..." << endl;
    //cout << "\nName: " << man2.name << "\nAge: " << man2.age << endl;

#pragma endregion

#pragma region Работа с файлами

    cout << "Пожалуйста, выберите пункт меню..." << endl;
    char choice;
    do
    {
        cout << "\n0 - выход из программы" << endl;
        cout << "1 - переименовать файл" << endl;
        cout << "2 - удалить файл" << endl;
        cout << "3 - посмотреть содержимое папки" << endl;
        cin >> choice;

        switch (choice)
        {
        case '1': RenameFile(); break;
        case '2': RemoveFile(); break;
        case '3': Dir(); break;
        }

    } while (choice != '0');

#pragma endregion

#pragma region Работа с директориями

    cout << "Пожалуйста, выберите пункт меню..." << endl;
    char ch;
    do
    {
        cout << "\n0 - выход из программы" << endl;
        cout << "1 - переименовать папку" << endl;
        cout << "2 - создать папку" << endl;
        cout << "3 - удалить папку" << endl;
        cin >> ch;

        switch (ch)
        {
        case '1': RenameDir(); break;
        case '2': CreateDir(); break;
        case '3': RemoveDir(); break;
        }

    } while (ch != '0');

#pragma endregion

    return 0;
}
