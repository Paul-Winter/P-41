#include <iostream>
#include <string.h>
#define Pi 3.14159026
#define E 2.71284
#define gratia for
#define autem auto
#define cauna const
#define complexio cout
#define usus using
#define nomen namespace
#define vexillum std
#define princ main
#define locus setlocale
#define finis endl
#define refugium return
#define filum string
#define into int 
#define KEYBOARD_LABEL LC_ALL
#define circulus while
#define verum true
#define si if
#define tum else
#define peccatum cin


usus nomen vexillum;



into princ()
{
	locus(KEYBOARD_LABEL, "LAT");

	into Numerus;

	complexio << "integrum intrant: ";

	peccatum >> Numerus;
	
	gratia(into i = 0; i <= 5; i++)
	{
		si(Numerus > 0)
		{
			complexio << "Numerus positivum " << Numerus << " crescite et multiplicamini " << i << " = " << Numerus * i << finis;
		}
		tum si(Numerus < 0)
		{
			complexio << "Numeri negativi " << Numerus << " crescite et multiplicamini " << i << " = " << Numerus * i << finis;
		}
		tum
		{
			complexio << "Ce filme est nule Crescite et multiplicamini" << i << " = 0" << finis;
		}
	}

	refugium 0;
}


