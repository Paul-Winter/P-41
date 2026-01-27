#include <iostream>

using namespace std;

// пример использования const_cast
void test_const_cast(const int* v)
{
    int* temp;
    // снимаем модификатор const
    temp = const_cast<int*>(v);
    // изменяем объект
    *temp = *v * *v;
}

// пример использования dynamic_cast
class Parent
{
public:
    virtual void Test()
    {
        cout << "Test Parent" << endl;
    }
};
class Child : public Parent
{
public:
    void Test()
    {
        cout << "Test Child" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    // явное и неявное преобразование типов
    double c = 2.2;
    double d = 2.2;
    cout << "double c = " << c << endl;
    cout << "int d = " << (int)d << endl;
    d = (char)10 / 3;

    // преобразование в стиле С
    cout << "(char)d = " << (char)d << endl;

    // const_cast - используется для явного переопределения модификаторов const и volatile
    // только const_cast может освободить от "обета постоянства" атрибута const
    int x = 10;
    cout << "До x = " << x << endl;
    test_const_cast(&x);
    cout << "После x = " << x << endl;

    // dynamic_cast - проверяет законность выполнения заданной операции приведения типа
    // если такую операцию выполнить нельзя, то выражение устанавливатся равным нулю
    Parent* ptr_p;
    Parent obj_p;
    Child* ptr_c;
    Child obj_c;
    ptr_c = dynamic_cast<Child*>(&obj_c);
    if (ptr_c)
    {
        cout << "Преобразование типов прошло успешно!" << endl;
        ptr_c->Test();
    }
    else
    {
        cout << "Преобразование типов невозможно!" << endl;
    }
    ptr_p = dynamic_cast<Parent*>(&obj_c);
    if (ptr_c)
    {
        cout << "Преобразование типов прошло успешно!" << endl;
        ptr_p->Test();
    }
    else
    {
        cout << "Преобразование типов невозможно!" << endl;
    }
    ptr_c = dynamic_cast<Child*>(&obj_p);
    if (ptr_c)
    {
        cout << "Преобразование типов прошло успешно!" << endl;
        ptr_c->Test();
    }
    else
    {
        cout << "Преобразование типов невозможно!" << endl;
    }

    // static_cast - аналог стандартной операции преобразования типов в стиле С
    // выполняет неполиморфное приведение типов, не выполняя никаких проверок
    for (int i = 0; i < 10; i++)
    {
        cout << "static_cast<double> = " << static_cast<double>(i) / 3 << endl;
        cout << "(double)i = " << (double)i / 3 << endl;
    }

    // reinterpret_cast - переводит один тип в совершенно другой
    // его следует использовать для перевода типов указателей, которые несовместимы по своей природе
    int x;
    const char* str = "Это строка!";
    cout << "str = " << str << endl;
    x = reinterpret_cast<int>(str);
    cout << "x = " << x << endl;

    return 0;
}
