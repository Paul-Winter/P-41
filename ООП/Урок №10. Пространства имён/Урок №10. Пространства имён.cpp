#include <iostream>
#include <string>

using namespace std;

namespace Bocharov
{
    class Animal
    {
    public:
        string vid;
    };
    void Hello()
    {
        cout << "Привет от Бочарова!" << endl;
    }
}
namespace Gazaryan
{
    class Animal
    {
    public:
        int age;
    };
    void Hello()
    {
        cout << "Привет от Газаряна!" << endl;
    }
}
namespace Dymochkina
{
    class Animal
    {
    public:
        string name;
    };
    void Hello()
    {
        cout << "Привет от Дымочкиной!" << endl;
    }
}

namespace A
{
    void Hello()
    {
        cout << "A" << endl;
    }

    namespace B
    {
        void Hello()
        {
            cout << "B" << endl;
        }
    }

    namespace C
    {
        void Hello()
        {
            cout << "C" << endl;
        }
    }
}

namespace
{
    void Hello()
    {
        cout << "Привет из неизвестности!" << endl;
    }
}

//void Hello()
//{
//    cout << "Hello, World!" << endl;
//}

//using namespace Bocharov;
int main()
{
    setlocale(LC_ALL, "");

    Bocharov::Animal animal;
    Dymochkina::Animal pet;

    animal.vid = "cat";
    pet.name = "Dusya";

    Bocharov::Hello();
    Gazaryan::Hello();
    Dymochkina::Hello();
    ::Hello();

    using Dymochkina::Animal;
    Animal pet2;

    Animal beast;

    Bocharov::Animal beast2;

    A::Hello();
    A::B::Hello();
    A::C::Hello();

    return 0;
}