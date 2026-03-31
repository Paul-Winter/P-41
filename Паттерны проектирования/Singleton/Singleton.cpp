// Singleton.cpp//

#include <iostream>

using namespace std;

class Singleton
{
private:
    static Singleton* instance;
    string name;
    Singleton()
    {

    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    string GetName()
    {
        return name;
    }
    void SetName(string _name)
    {
        this->name = _name;
    }
    static Singleton* GetInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;

int main()
{
    setlocale(LC_ALL, "");

    Singleton* first = Singleton::GetInstance();
    first->SetName("одиночка");
    cout << "имя объекта №1: " << first->GetName() << endl;

    Singleton* second = Singleton::GetInstance();
    cout << "имя объекта №2: " << second->GetName() << endl;

    Singleton* third = Singleton::GetInstance();
    cout << "имя объекта №3: " << third->GetName() << endl;

    return 0;
}
