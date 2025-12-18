#include <iostream>
#include <string.h>

using namespace std;

class Human
{
public:
    string name;
    int age;
//private:
    // inner class
    class Organ
    {
    public:
        string name;
        int weight;
        Organ(int _weight) : weight{ _weight } {}
        void PrintOrgan()
        {
            cout << "Organ weight is " << weight << " gramm" << endl;
        }
    };
public:
    Human(int _age) : age{ _age } {}
    Human(string _name) : name{_name} {}
    void PrintHuman()
    {
        cout << "Human name is " << name << " age: " << age << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");
    
    Human human("Ivan");
    human.age = 17;
    human.PrintHuman();

    Human::Organ appendex(200);
    appendex.PrintOrgan();
    
    return 0;
}
