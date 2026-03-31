#include <iostream>

using namespace std;

class Organ
{
private:
    string name;
public:
    string GetName()
    {
        return name;
    }
    void SetName(string _name)
    {
        this->name = _name;
    }
};

class Human
{
private:
    string name;
    Organ* heart;
public:
    string GetName()
    {
        return name;
    }
    void SetName(string _name)
    {
        this->name = _name;
    }
    Human()
    {
        this->heart = new Organ;
    }
};

class IWork
{
public:
    virtual void Work() = 0;
};

class Employee : public Human, public IWork
{
private:
    double salary;
public:
    double GetSalary()
    {
        return salary;
    }
    void SetSalary(double _salary)
    {
        this->salary = _salary;
    }
    virtual void Work() override
    {
        cout << "работник работает" << endl;
    }
};

class Workplace
{
private:
    int number;
    Employee worker;
public:
    int GetNumber()
    {
        return number;
    }
    void SetNumber(int _number)
    {
        this->number = _number;
    }
    Workplace(Employee employee)
    {
        this->worker = employee;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    cout << "Привет, Мир!" << endl;

    return 0;
}
