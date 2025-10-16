#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

struct Item
{
    char title[20];
    unsigned int qty;
    float price;
};

int main()
{
    setlocale(LC_ALL, "");

    /*
    int i = 0;
    FILE* myFile;
    Item shop[10];
    const char* path = "C:\\Users\\Student\\P-41\\Урок №19. Работа с файлами\\myFile.txt";

    if ((fopen_s(&myFile, path, "r")) != NULL)
        cout << "Указанный файл не может быть открыт!";
    else
    {
        while (!feof(myFile))
        {
            fscanf_s(myFile, "%s", shop[i].title, sizeof(shop[i].title));
            fscanf_s(myFile, "%u", &shop[i].qty, sizeof(shop[i].qty));
            fscanf_s(myFile, "%f", &shop[i].price, sizeof(shop[i].price));
            cout << shop[i].title << " " << shop[i].qty << " " << shop[i].price << endl;
            i++;
        }

        //if (fclose(myFile) == EOF)
        //    cout << "Файл не закрыт!";
        //else
        //    cout << "Файл закрыт успешно!";
    }
    cout << endl;
    */

    const char* path = "C:\\Users\\Student\\P-41\\Урок №19. Работа с файлами\\testFile.txt";
    int symbol;
    int length = 0;
    int count = 0;
    FILE* myFile;
    const int size = 128;
    char buffer[size];

    if (fopen_s(&myFile, path, "r") != NULL)
    {
        cout << "Невозможно открыть файл!" << endl;
    }
    else
    {
        while (!feof(myFile))
        {
            fgets(buffer, (size - 1), myFile);
            length = strlen(buffer);
            if (buffer[length - 1] == '\n')
            {
                buffer[length - 1] = '\0';
            }
            puts(buffer);
        }
    }

    return 0;
}

