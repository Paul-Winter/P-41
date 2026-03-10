// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

class Subsystem1
{
public:
    string Operation1()
    {
        return "Subsystem1\n";
    }
};

class Subsystem2
{
public:
    string Operation2()
    {
        return "Subsystem2\n";
    }
};

class Facade
{
protected:
    Subsystem1* subsystem1;
    Subsystem2* subsystem2;

public:
    Facade()
    {
        Subsystem1* subsystem1 = new Subsystem1();
        Subsystem2* subsystem2 = new Subsystem2();
    }

    string Operation()
    {
        string result = "Facade working!\n";
        result += subsystem1->Operation1();
        result += subsystem2->Operation2();
        return result;
    }
};

class Device
{
public:
    virtual void onOff() = 0;
    virtual int getVolume() = 0;
    virtual int getChannel() = 0;
    virtual void setVolume(int volume) = 0;
    virtual void setChannel(int channel) = 0;
};

class Control
{
protected:
    Device* device;
public:
    Control(Device* dev) : device(dev)
    {

    }
    void volumeDown()
    {
        int vol = device->getVolume();
        device->setVolume(vol - 10);
        cout << "volumeDown" << endl;
    }
};

class RemoteControl : public Control
{
public:
    RemoteControl(Device* dev) : Control(dev)
    {

    }
    void mute()
    {
        device->setVolume(0);
        cout << "remoteControl mute" << endl;
    }
};

class TV : public Device
{
private:
    bool enabled;
    int volume;
    int channel;
public:
    TV() : enabled(false), volume(0), channel(1)
    {

    }
    void onOff() override
    {
        if (enabled)
        {
            enabled = false;
        }
        else
        {
            enabled = true;
        }
    }
    int getVolume() override
    {
        return volume;
    }
    void setVolume(int vol) override
    {
        volume = vol;
    }
    int getChannel() override
    {
        return channel;
    }
    void setChannel(int ch) override
    {
        channel = ch;
    }
};



int main()
{
    Facade* facade = new Facade();
    cout << facade->Operation() << endl;

    TV* tv = new TV();
    Control* tvControl = new Control(tv);
    RemoteControl* tvRemoteControl = new RemoteControl(tv);

    tvControl->volumeDown();
    tvRemoteControl->mute();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
