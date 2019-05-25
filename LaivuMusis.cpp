#include "pch.h"
#include <iostream>
#include "Botas.h"
#include "Zmogus.h"
#include "Lenta.h"
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

	Zmogus z;
	Botas b;




	z.Spausdink();
	z.dekKeturvieti();
	system("cls");
	z.Spausdink();

	for (int i = 0; i < 2; i++)
	{
		z.dekTrivieti();
		system("cls");
		z.Spausdink();
	}

	for (int i = 0; i < 3; i++)
	{
		z.dekDvivieti();
		system("cls");
		z.Spausdink();
	}

	for (int i = 0; i < 4; i++)
	{
		z.dekVienvieti();
		system("cls");
		z.Spausdink();
	}

	system("cls");

	z.pasalinkZvaig();

	srand(time(0));
	int br = rand() % 7;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			z.setBotoL(i, j, b.sudekLaivus(i, j, br));
			b.setZL(i, j, z.getL(i, j));
		}
	}

	while (1)
	{

		b.spausdinkZL();
		z.spausdinkB();
		z.sauna();
		if (z.getS() == 10) {
			break;
		}
		b.saudo();
		if (b.getS() == 10) {
			break;
		}
		system("pause");
		system("cls");

	}

	system("cls");
	b.spausdinkZL();
	z.spausdinkB();

	if (b.getS() > z.getS()) cout << "\n\n\n LAIMEJO BOTAS!!\n";
	else cout << "\n\n Laimejo zmogus\n\n";

	system("pause");


	return 0;

}
