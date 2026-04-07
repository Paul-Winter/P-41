#include <iostream>

using namespace std;

class Target
{
public:
    virtual string Request() const
    {
        return "Default target";
    }
};
class Adaptee
{
public:
    string SpecifiedRequest() const
    {
        return "Specified request from Adaptee";
    }
};
class Adapter : public Target
{
private:
    Adaptee* adaptee;
public:
    Adapter(Adaptee* adapt) : adaptee{adapt} {}
    string Request() const override
    {
        return "Adapter: " + this->adaptee->SpecifiedRequest();
    }
};

class USBCable
{
public:
    virtual string Socket() const
    {
        return "Подключение USB-кабеля";
    }
};
class LightningCable
{
public:
    string AppleSocket() const
    {
        return "Подключение через lightning-кабель";
    }
};
class TypeCCable : public USBCable
{
private:
    LightningCable* adaptee;
public:
    TypeCCable(LightningCable* adapt) : adaptee{ adapt } {}
    string Socket() const override
    {
        return "Подключаем переходник " + this->adaptee->AppleSocket();
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Target* target = new Target;
    cout << target->Request() << endl;
    Adaptee* adaptee = new Adaptee;
    cout << adaptee->SpecifiedRequest() << endl;
    Adapter* adapter = new Adapter(adaptee);
    cout << adapter->Request() << endl;
    cout << "___________________________________________________________________________________" << endl;

    USBCable* usb = new USBCable;
    cout << usb->Socket() << endl;
    LightningCable* app = new LightningCable;
    cout << app->AppleSocket() << endl;
    TypeCCable* typeC = new TypeCCable(app);
    cout << typeC->Socket() << endl;

    return 0;
}
