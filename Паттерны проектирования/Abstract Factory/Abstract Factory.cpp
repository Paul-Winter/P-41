#include <iostream>

using namespace std;

class Box
{

};
class BlackBox : public Box
{
public:
    BlackBox()
    {
        cout << "Чёрный корпус" << endl;
    }
};
class SilverBox : public Box
{
public:
    SilverBox()
    {
        cout << "Металлический корпус с ргб подсветкой" << endl;
    }
};

class Processor
{
    
};
class AMD : public Processor
{
public:
    AMD()
    {
        cout << "Процессор AMD" << endl;
    }
};
class INTEL : public Processor
{
public:
    INTEL()
    {
        cout << "Процессор INTEL" << endl;
    }
};
class MainBoard
{

};
class MSI : public MainBoard
{
public:
    MSI()
    {
        cout << "Материнская плата MSI" << endl;
    }
};
class ASUS : public MainBoard
{
public:
    ASUS()
    {
        cout << "Материнская плата ASUS" << endl;
    }
};
class HDD
{

};
class SmallDisc : public HDD
{
public:
    SmallDisc()
    {
        cout << "500ГБ" << endl;
    }
};
class BigDisc : public HDD
{
public:
    BigDisc()
    {
        cout << "1ТБ" << endl;
    }
};
class Memory
{

};
class GameMemo : public Memory
{
public:
    GameMemo()
    {
        cout << "16ГБ ОЗУ" << endl;
    }
};
class OfficeMemo : public Memory
{
public:
    OfficeMemo()
    {
        cout << "8ГБ ОЗУ" << endl;
    }
};

class PCFactory
{
public:
    virtual Box* CreateBox() = 0;
    virtual Processor* CreateProcessor() = 0;
    virtual MainBoard* CreateMainBoard() = 0;
    virtual HDD* CreateHDD() = 0;
    virtual Memory* CreateMemory() = 0;
};
class PC
{
    Box* box;
    Processor* processor;
    MainBoard* mainBoard;
    HDD* hdd;
    Memory* memory;
public:
    PC()
    {
        box = NULL;
        processor = NULL;
        mainBoard = NULL;
        hdd = NULL;
        memory = NULL;
    }
    Box* GetBox()
    {
        return box;
    }
    Processor* GetProcessor()
    {
        return processor;
    }
    MainBoard* GetMainBoard()
    {
        return mainBoard;
    }
    HDD* GetHDD()
    {
        return hdd;
    }
    Memory* GetMemory()
    {
        return memory;
    }
    void SetBox(Box* _box)
    {
        this->box = _box;
    }
    void SetProcessor(Processor* _processor)
    {
        this->processor = _processor;
    }
    void SetMainBoard(MainBoard* _mainBoard)
    {
        this->mainBoard = _mainBoard;
    }
    void SetHDD(HDD* _hdd)
    {
        this->hdd = _hdd;
    }
    void SetMemory(Memory* _memory)
    {
        this->memory = _memory;
    }
};
class OfficePC : public PCFactory
{
public:
    Box* CreateBox()
    {
        return new BlackBox();
    }
    Processor* CreateProcessor()
    {
        return new AMD();
    }
    MainBoard* CreateMainBoard() 
    {
        return new ASUS();
    }
    HDD* CreateHDD()
    {
        return new SmallDisc();
    }
    Memory* CreateMemory()
    {
        return new OfficeMemo();
    }
    OfficePC()
    {

    }
};
class GamePC : public PCFactory
{
public:
    Box* CreateBox()
    {
        return new SilverBox();
    }
    Processor* CreateProcessor()
    {
        return new INTEL();
    }
    MainBoard* CreateMainBoard()
    {
        return new MSI();
    }
    HDD* CreateHDD()
    {
        return new BigDisc();
    }
    Memory* CreateMemory()
    {
        return new GameMemo();
    }
    GamePC()
    {

    }
};
class PC_Configurator
{
    PCFactory* pcFactory;
public:
    PC_Configurator()
    {
        pcFactory = NULL;
    }
    PCFactory* GetPCFactoy()
    {
        return pcFactory;
    }
    void SetPCFactory(PCFactory* _pcFactory)
    {
        this->pcFactory = _pcFactory;
    }
    void Configure(PC* pc)
    {
        pc->SetBox(pcFactory->CreateBox());
        pc->SetProcessor(pcFactory->CreateProcessor());
        pc->SetMainBoard(pcFactory->CreateMainBoard());
        pc->SetHDD(pcFactory->CreateHDD());
        pc->SetMemory(pcFactory->CreateMemory());
    }
};
int main()
{
    setlocale(LC_ALL, "RU");
    
    PC* homePC = new PC;
    OfficePC* office = new OfficePC;
    GamePC* game = new GamePC;
    PC_Configurator confPC;
    confPC.SetPCFactory(game);
    confPC.Configure(homePC);
    cout << "_____________________________________________________________________" << endl;
    confPC.SetPCFactory(office);
    confPC.Configure(homePC);

    return 0;
}

