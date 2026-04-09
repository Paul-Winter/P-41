#include <iostream>

using namespace std;

class Sensor
{
public:
    void A1() { cout << "сработал датчик движения" << endl; }
};
class ElectricThings
{
public:
    void B1() { cout << "отключается робот-пылесос" << endl; }
    void B2() { cout << "работает телевизор" << endl; }
};
class Lightning
{
public:
    void C1() { cout << "свет в прихожей" << endl; }
    void C2() { cout << "свет на кухне" << endl; }
    void C3() { cout << "свет в ванной" << endl; }
};
class Facade
{
private:
    Sensor* ssa;
    ElectricThings* ssb;
    Lightning* ssc;
public:
    Facade()
    {

    }
    void GreetingMaster()
    {
        ssa->A1();
        ssb->B1();
        ssc->C1();
    }
    void CookingFood()
    {
        ssb->B2();
        ssc->C2();
    }
    void Washing()
    {
        ssc->C3();
    }
};
class Pedal
{
public:
    void Gas() { cout << "скорость увеличивается" << endl; }
    void Brake() { cout << "скорость уменьшается " << endl; }
};
class Wheel
{
public:
    void ToRight() { cout << "направо" << endl; }
    void ToLeft() { cout << "налево" << endl; }
};
class Headlights
{
public:
    void Near() { cout << "включаются ближние фары" << endl; }
    void Further() { cout << "включаются дальние фары" << endl; }
};
class Wipers
{
public:
    void Wash() { cout << "сработали дворники" << endl; }
};
class Display
{
public:
    void Bluetooth() { cout << "подключить устройство по блютузу" << endl; }
    void Call() { cout << "принять звонок" << endl; }
    void Radio() { cout << "включить радио" << endl; }
    void Camera() { cout << "включается камера заднего вида" << endl; }
    void Navigator() { cout << "включить навигатор" << endl; }
};
class Signal
{
public:
    void BeepBeep() { cout << "гудок" << endl; }
};
class Auto
{
private:
    Pedal* pedal;
    Wheel* wheel;
    Headlights* headlights;
    Wipers* wipers;
    Display* display;
    Signal* signal;
public:
    Auto()
    {

    }
    void SunshineDrive()
    {
        pedal->Gas();
        wheel->ToLeft();
        display->Radio();
        signal->BeepBeep();
    }
    void RainNghtDrive()
    {
        pedal->Gas();
        headlights->Further();
        display->Navigator();
        wipers->Wash();
        pedal->Brake();
        wipers->Wash();
    }
    
};
int main()
{
    setlocale(LC_ALL, "");

    Facade* facade = new Facade();
    cout << "Владелец умного дома пришёл домой" << endl;
    facade->GreetingMaster();
    cout << "Владелец захотел покушать" << endl;
    facade->CookingFood();
    cout << "Владелец решил принять душ" << endl;
    facade->Washing();

    cout << "--------------------------" << endl;

    Auto* lamba = new Auto();
    cout << "Водитель сел за руль" << endl;
    lamba->RainNghtDrive();
    cout << "дождь закончился" << endl;
    lamba->SunshineDrive();

    return 0;
}
