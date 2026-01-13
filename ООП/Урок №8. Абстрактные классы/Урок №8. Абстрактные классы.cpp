#include <iostream>

using namespace std;

// абстрактный класс
class A
{
    //чисто виртуальная функция = 0 - чистый спецификатор
    virtual void SomeFunction() = 0;
};

class Pet
{
protected:
    int age;
    string name;
    //string say;
    int tailsize;
public:
    Pet(int age, string name, int tailsize) : age{ age }, name{ name }, tailsize{ tailsize }{}
    Pet() : Pet(10, "Питомец безымянный", 5){}
    /*string getSay()
    {
        return say;
    }*/

    virtual void say() = 0;
    virtual void show()
    {
        cout << "Имя: " << name << endl;
    }
};

class Dog :public Pet
{
protected:
    string breed;
public:
    Dog(int age, string name, int tailsize, string breed) :breed{ breed } 
    {
        this->age = age;
        this->name = name;
        this->tailsize = tailsize;
    }
    Dog() : Dog(5, "Собака безымянная", 10, "Бульдог") {}
    virtual void say()
    {
        cout << "Гав-гав"<<endl;
    }
    virtual void show()
    {
        cout << "Имя: " << name << endl;
        cout << "Порода: " << breed << endl;
    }
};
class Cat :public Pet
{
protected:
    string breed;

public:
    Cat(int age, string name, int tailsize, string breed) :breed{ breed }
    {
        this->age = age;
        this->name = name;
        this->tailsize = tailsize;
    }
    Cat() : Cat(7, "Кот безымянный", 15, "Сиамский") {}
    virtual void say()
    {
        cout << "Мяу-мяу" << endl;
    }
    virtual void show()
    {
        cout << "Имя: " << name << endl;
        cout << "Порода: " << breed << endl;
    }
};

class Animal
{
protected:
    string name;
    virtual void Show() = 0;
    virtual void Say() = 0;
};

class Frog: public Animal
{
    string color;
public:
    Frog(string color,string name)
    {
        this->color = color;
        this->name = name;
    }
    Frog():Frog("зелёная","Квакуша"){}
    virtual void Show()
    {
        cout << "Лягушка " << name << " " << color << endl;
    }
    virtual void Say() { cout << "Ква-ква" << endl; }
};
class Giraffe : public Animal
{
    int neck;
public:
    Giraffe(int neck, string name)
    {
        this->neck = neck;
        this->name = name;
    }
    Giraffe() :Giraffe(2, "Толик") {}
    virtual void Show()
    {
        cout << "Жираф " << name << ", шея " << neck << "м" << endl;
    }
    virtual void Say() { cout << "Shhhh" << endl; }
};


int main()
{
    setlocale(LC_ALL, "");

    Dog dog;
    Cat cat;
    dog.show();
    dog.say();
    cat.show();
    cat.say();
    //Pet pet;
    
    //Animal beast;
    Frog frog;
    Giraffe giraffe;
    frog.Show();
    frog.Say();
    giraffe.Show();
    giraffe.Say();

    return 0;
}
