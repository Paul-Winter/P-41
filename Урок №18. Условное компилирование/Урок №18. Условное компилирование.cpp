#include <iostream>
#include "array.h"

#define напиши std::cout<<
#define получи std::cin>>
#define заново <<std::endl;
#define старт int
#define _уем main(){
#define хва return
#define _тит 0;}

//директивы препроцессора для условной компиляции:
//#if
//#ifdef
//#ifndef
//#else
//#endif
//#elif

#define First 3
#define Second 4

#if First * Second == 9
int main()
{
    setlocale(LC_ALL, "");
    напиши "составная директива условного включения" заново
    return 0;
}
#elif First * Second == 15
старт _уем
    напиши "i got a five!" заново
хва _тит
#else
int main()
{
    setlocale(LC_ALL, "");
    
    const int size = 5;
    int arr[size] = { 9, 18, 41, 21, 88 };
#define покажи_массив ShowArray(
    покажи_массив arr, size);
    cout << "Минимум: " << GetMin(arr, size) << endl;
    cout << "Максимум: " << GetMax(arr, size) << endl;

    return 0;
}
#endif

