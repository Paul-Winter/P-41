#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void some_func()
{
    //!!! привычный способ
    FILE* f;

    if (!(f = fopen("test.txt", "r+")))
    {
        // не удалось открыть файл
        exit(0);
    }
    // удалось, работаем дальше с файлом

    // закрываем файл после работы с ним
    fclose(f);

    //!!! ООП подход
    //FileOpen myFile("test.txt", "r+");
}

class FileOpen
{
    //FILE* f;
public:
    //FileOpen(const char* filename, const char* mode)
    //{
    //    if (!(f = fopen(filename, mode)))
    //    {
    //        // не удалось открыть файл
    //        exit(0);
    //    }
    //}
    FileOpen()
    {

    }
    ~FileOpen()
    {
        //fclose(f);
    }
    void Test()
    {
        cout << "TEST" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    cout << "__________Специальная_встроенная_библиотека_STL_содержит_объекты:__________" << endl << endl;
    cout << "Контейнер  - блок для хранения данных, управления ими и размещения." << endl;
    cout << "Алгоритм   - специальная функция для работы с данными, содержащимися в контейнере." << endl;
    cout << "Итератор   - специальный указатель, который позволяет алгоритмам перемещаться в контейнере." << endl;
    cout << "Функторы   - механизм для инкапсулирования функций в конкретном объекте для использования другими компонентами." << endl;

    cout << "Аллокатор  - распределитель памяти." << endl;
    cout << "Предикат   - функция нестандартного типа, используемая в контейнере." << endl;
    cout << endl << endl;

    // создаём два автоматических указателя
    auto_ptr<FileOpen> ptr1(new FileOpen);
    auto_ptr<FileOpen> ptr2;

    // передача права владения
    ptr2 = ptr1;
    ptr2->Test();

    // присваивание автоматического указателя обычному укзателю на объект класса
    FileOpen* ptr = ptr2.get();
    ptr->Test();

    return 0;
}
