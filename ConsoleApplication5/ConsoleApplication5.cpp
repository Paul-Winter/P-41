#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	char i = 0;
	cout << "Введите символ ";
	cin >> i;
	/*for (int j = 0; j < 200; j++)
	{
		cout << j << " " << char(j) << endl;
	}*/
	if (int(i) >= 48 && int(i) <= 57)
	{
		cout << "Цифра"<<endl;
	}
	else if((int(i)>=65 && int(i)<=90)||(int(i)>=97 &&int(i)<=122))
	{
		cout << "Буква"<<endl;
	}
	else
	{
		cout << "Спец символ"<<endl;
	}
}


