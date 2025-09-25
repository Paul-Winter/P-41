
#include <iostream>
using namespace std;

struct car
{
    double longcar;
    double clirens;
    double VEngine;
    int P;
    double d;
    string color;
    string box;
};

car carselect(double longc,double clir,double bEng,int PC,double dC, string color, string box)
{
    car machine = { longc,clir,bEng,PC,dC,color,box };
    return machine;
}

int main()
{
    setlocale(LC_ALL, "");

}