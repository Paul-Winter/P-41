#include <iostream>
#include "ModelNim.h"
#include "ViewNim.h"
#include "ControllerNim.h"
//#include "Model.h"
//#include "View.h"
//#include "Controller.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    //ModelTemperature model;
    //ViewTemperature view(&model);
    //ControllerTemperature controller(&model);
    //controller.Start();

    ModelNim model;
    ViewNim view(&model);
    ControllerNim controller(&model);
    controller.Start();

    return 0;
}
