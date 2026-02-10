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

int main()
{
    setlocale(LC_ALL, "");

#pragma region Сохранение объектов в файл

    // создаём объекты структуры (класса)
    Human man;
    Human man2;

    cout << "\nВведите имя: ";
    cin >> man.name;
    cout << "\nВведите возраст: ";
    cin >> man.age;

    // открываем файл на запись
    FILE* f = fopen("test.txt", "w+");
    if (!f)
    {
        exit(0);
    }

    // запись первого объекта в файл
    fwrite(&man, sizeof(Human), 1, f);    
    fclose(f);

    // открываем файл на чтение
    f = fopen("test.txt", "r+");
    if (!f) exit(0);

    // считывание содержимого файла в объект
    fread(&man2, sizeof(Human), 1, f);
    fclose(f);

    cout << "считывание содержимого файла в объект..." << endl;
    cout << "\nName: " << man2.name << "\nAge: " << man2.age << endl;

#pragma endregion



    return 0;
}
