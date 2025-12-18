#include <iostream>
#include <string.h>

using namespace std;

class Parent
{
protected:
    string name;
    int age;
    //int fingersCount;
public:
    Parent()
    {
        cout << "Вызов конструктора родителя" << endl;
        name = "";
        age = 0;
    }
    Parent(string _name, int _age) : name {_name}, age {_age}
    {
        //fingersCount = 0;
    }
    void SetName(string _name)
    {
        name = _name;
    }
    void SetAge(int _age)
    {
        age = _age;
    }
    //void SetFingers(int count)
    //{
    //    fingersCount = count;
    //}
    void Show()
    {
        cout << "Human " << name << " " << age << " years old" << endl;
        //cout << "Fingers count " << fingersCount << endl;
    }
};

class Child : public Parent
{
    int fingersCount;
public:
    Child(string _name, int _age, int _count)
    {
        cout << "Вызов конструктора наследника" << endl;
        this->name = _name;
        this->age = _age;
        this->fingersCount = _count;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    //Parent human("Ivan", 23);
    //human.Show();
    //human.SetAge(17);
    ////human.SetFingers(10);
    //human.Show();

    Child baby("Vanechka", 1, 10);
    baby.Show();

    return 0;
}
