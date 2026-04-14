#include <iostream>

using namespace std;

class IStrategy
{
public:
    virtual void Operation() = 0;
};
class ConcreteStrategy1 : public IStrategy
{
public:
    void Operation() override
    {
        cout << "Concrete Strategy #1" << endl;
    }
};
class ConcreteStrategy2 : public IStrategy
{
public:
    void Operation() override
    {
        cout << "Concrete Strategy #2" << endl;
    }
};
class Context
{
private:
    IStrategy* strategy;
public:
    void SetStrategy(IStrategy* strategy)
    {
        this->strategy = strategy;
    }
    void ExecuteOperation()
    {
        strategy->Operation();
    }
};
class IShooting
{
public:
    virtual void Shooting() = 0;
};
class Pistol : public IShooting
{
private:
    string name;
public:
    string GetName()
    {
        return name;
    }
    void Shooting() override
    {
        cout << "стреляет из пистолета " << name << endl;
    }
    Pistol(string name)
    {
        this->name = name;
    }
};
class ShotGun : public IShooting
{
private:
    string name;
public:
    string GetName()
    {
        return name;
    }
    void Shooting() override
    {
        cout << "стреляет из автомата " << name << endl;
    }
    ShotGun(string name)
    {
        this->name = name;
    }
};
class Player
{
private:
    IShooting* shooting;
public:
    void SetGun(IShooting* shooting)
    {
        this->shooting = shooting;
    }
    void Shooting()
    {
        shooting->Shooting();
    }
    Player()
    {
        cout << "создан персонаж игрока" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Context context;
    IStrategy* cs1 = new ConcreteStrategy1();
    IStrategy* cs2 = new ConcreteStrategy2();

    context.SetStrategy(cs1);
    context.ExecuteOperation();
    
    context.SetStrategy(cs2);
    context.ExecuteOperation();

    cout << "____________________________________________________________________________" << endl;

    Player* player = new Player();
    IShooting* pistol = new Pistol("Глок");
    IShooting* shotGun = new ShotGun("АК-74");

    cout << "игрок подбирает новое оружие" << endl;
    player->SetGun(pistol);
    player->Shooting();

    cout << "игрок подбирает новое оружие" << endl;
    player->SetGun(shotGun);
    player->Shooting();

    return 0;
}
