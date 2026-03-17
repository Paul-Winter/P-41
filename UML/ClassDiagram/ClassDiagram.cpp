#include <iostream>

using namespace std;

class Position
{
private:
    double MinimalSalary;
    string Name;

public:
    double GetMinSalary()
    {
        return MinimalSalary;
    }
    string GetName()
    {
        return Name;
    }
    Position(string _name, double _minimalSalary) : Name {_name}, MinimalSalary {_minimalSalary}
    {        
    }
};

int main()
{
    setlocale(LC_ALL, "");

    cout << "Привет, Мир!" << endl;

    return 0;
}
