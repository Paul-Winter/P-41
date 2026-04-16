#include <iostream>
#include "Model.h"
#include "View.h"
#include "Controller.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    Model model;
    View view(&model);
    Controller controller(&model);
    controller.Start();

    return 0;
}
