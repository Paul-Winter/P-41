#include <iostream>

using namespace std;

class Component
{
public:
    Component() {}
    virtual ~Component() {}
    virtual string Operation() const = 0;
};
class Gun : public Component
{
public:
    string Operation() const override
    {
        return "Стрельба из ружья";
    }
};

class Pistol : public Component
{
public:
    string Operation() const override
    {
        return "Стрельба из пистолета";
    }
};

class Decorator : public Component
{
protected:
    Component* component;
public:
    Decorator(Component* comp) : component{comp} {}
    string Operation() const override
    {
        return this->component->Operation();
    }
};

class Pricel : public Decorator
{
public:
    Pricel(Component* comp) : Decorator(comp) {}
    string Operation() const override
    {
        return Decorator::Operation() + " с прицелом";
    }
};

class Glushitel : public Decorator
{
public:
    Glushitel(Component* comp) : Decorator(comp) {}
    string Operation() const override
    {
        return Decorator::Operation() + " с глушителем";
    }
};

class Burger
{
public:
    Burger()
    {

    }
    virtual string Make() const = 0;
};
class Hamburger : public Burger
{
public:
    string Make() const override
    {
        return "Гамбургер";
    }
};
class Cheeseburger : public Burger
{
public:
    string Make() const override
    {
        return "Чизбургер";
    }
};
class BurgerDecorator : public Burger
{
protected:
    Burger* burger;
public:
    BurgerDecorator(Burger* burg) : burger{ burg } {}
    string Make() const override
    {
        return this->burger->Make();
    }
};

class Cothlete : public BurgerDecorator
{
public:
    Cothlete(Burger* burg) : BurgerDecorator( burg ) {}
    string Make() const override
    {
        return BurgerDecorator::Make() + " с котлетой";
    }
};
class Souce : public BurgerDecorator
{
public:
    Souce(Burger* burg) : BurgerDecorator(burg) {}
    string Make() const override
    {
        return BurgerDecorator::Make() + " с соусом";
    }
};
class Salad : public BurgerDecorator
{
public:
    Salad(Burger* burg) : BurgerDecorator(burg) {}
    string Make() const override
    {
        return BurgerDecorator::Make() + " с салатом";
    }
};
class Tomato : public BurgerDecorator
{
public:
    Tomato(Burger* burg) : BurgerDecorator(burg) {}
    string Make() const override
    {
        return BurgerDecorator::Make() + " с помидором";
    }
};
class Pickle : public BurgerDecorator
{
public:
    Pickle(Burger* burg) : BurgerDecorator(burg) {}
    string Make() const override
    {
        return BurgerDecorator::Make() + " с маринованными огурцами";
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Component* comp = new Gun;
    cout << "Ружье: " << comp->Operation() << endl;
    Component* decorA = new Pricel(comp);
    cout << decorA->Operation() << endl;
    Component* decorB = new Glushitel(comp);
    cout << decorB->Operation() << endl;

    comp = new Pistol;
    cout << comp->Operation() << endl;
    decorA = new Pricel(comp);
    cout << decorA->Operation() << endl;
    decorB = new Glushitel(decorA);
    cout << decorB->Operation() << endl;

    Burger* hamburger = new Hamburger;
    Burger* cheeseburger = new Cheeseburger;
    cout << hamburger->Make() << endl;
    cout << cheeseburger->Make() << endl;
    Burger* souceham = new Souce(hamburger);
    Burger* scham = new Cothlete(souceham);
    Burger* saladcheese = new Salad(cheeseburger);
    Burger* stcheese = new Tomato(saladcheese);
    Burger* stpcheese = new Pickle(stcheese);
    cout << scham->Make() << endl;
    cout << stpcheese->Make() << endl;

    return 0;
}
