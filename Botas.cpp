#include "pch.h"
#include "Botas.h"
#include "Lenta.h"
#include <iostream>
#include <windows.h>
#include <MMSystem.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>



using namespace std;



Botas::Botas()
{
	pPA = 5;
	pPB = 5;
	sunL = 0;
	ss5 = 0;
	saudymoS = 0;
	pataikeA = -1;
	pataikeB = -1;
	sunaikinoLaivu = 0;
}

void Botas::setZL(int i, int j, char c)
{
	zmogausL[i][j] = c;
}

int Botas::getS()
{
	return sunaikinoLaivu;
}

void Botas::saudo()
{

	if (saudymoS == 0)
	{

		while (1)
		{
			bool l = true;
			int a, b;
			srand(time(0));
			a = rand() % 10;
			b = rand() % 10;

			for (int i = a; i < a + 3; i++) {
				for (int j = b; j < b + 3; j++) {
					if (i < 11 && j < 11) {
						if (zmogausL[i][j] == '$')
						{
							l = false;
						}
					}
				}
			}

			if (l) {
				if (zmogausL[a + 1][b + 1] == '#')
				{
					zmogausL[a + 1][b + 1] = 'x';
					pataikeA = a + 1;
					pataikeB = b + 1;
					pPA = pataikeA;
					pPB = pataikeB;
					saudymoS++;
					break;
				}
				if (zmogausL[a + 1][b + 1] == '-')
				{
					zmogausL[a + 1][b + 1] = '.';
					pataikeA = -1;
					pataikeB = -1;
					break;
				}

			}
		}

	}


	else if (saudymoS == 1) {

		if (zmogausL[pataikeA][pataikeB - 1] == '-')
		{
			zmogausL[pataikeA][pataikeB - 1] = '.';

		}
		else if (zmogausL[pataikeA][pataikeB - 1] == '#')
		{
			zmogausL[pataikeA][pataikeB - 1] = 'x';
			pataikeB--;
			saudymoS = 5;

		}

		else if (zmogausL[pataikeA][pataikeB + 1] == '-')
		{
			zmogausL[pataikeA][pataikeB + 1] = '.';

		}
		else if (zmogausL[pataikeA][pataikeB + 1] == '#')
		{
			zmogausL[pataikeA][pataikeB + 1] = 'x';
			saudymoS = 7;
			pataikeB++;
			pPB++;

		}



		else if (zmogausL[pataikeA - 1][pataikeB] == '-')
		{
			zmogausL[pataikeA - 1][pataikeB] = '.';

		}
		else if (zmogausL[pataikeA - 1][pataikeB] == '#')
		{
			zmogausL[pataikeA - 1][pataikeB] = 'x';
			saudymoS = 6;
			pataikeA--;

		}

		else if (zmogausL[pataikeA + 1][pataikeB] == '-')
		{
			zmogausL[pataikeA + 1][pataikeB] = '.';

		}
		else if (zmogausL[pataikeA + 1][pataikeB] == '#')
		{
			zmogausL[pataikeA + 1][pataikeB] = 'x';
			pataikeA++;
			pPA++;
			saudymoS = 8;

		}


	}



	else if (saudymoS == 5)
	{
		if (zmogausL[pataikeA][pataikeB - 1] == '#') {
			pataikeB--;
			zmogausL[pataikeA][pataikeB] = 'x';

		}
		else if (zmogausL[pataikeA][pataikeB - 1] == '-') {
			zmogausL[pataikeA][pataikeB - 1] = '.';
			saudymoS = 7;

		}
		else if (zmogausL[pataikeA][pataikeB - 1] == '.' || (pataikeB - 1) == 0) {
			saudymoS = 71;
		}
	}
	else if (saudymoS == 7)
	{
		if (zmogausL[pPA][pPB + 1] == '#') {
			pPB++;

			zmogausL[pPA][pPB] = 'x';
		}
		else {

			saudymoS = 0;
		}
	}




	else if (saudymoS == 6)
	{
		if (zmogausL[pataikeA - 1][pataikeB] == '#') {
			pataikeA--;
			zmogausL[pataikeA][pataikeB] = 'x';

		}
		else if (zmogausL[pataikeA - 1][pataikeB] == '-') {
			zmogausL[pataikeA - 1][pataikeB] = '.';
			saudymoS = 8;

		}
		else if (zmogausL[pataikeA - 1][pataikeB] == '.' || (pataikeA - 1) == 0) {
			saudymoS = 61;
		}


	}

	else if (saudymoS == 8)
	{
		if (zmogausL[pPA + 1][pPB] == '#') {
			pPA++;

			zmogausL[pPA][pPB] = 'x';
		}
		else {

			saudymoS = 0;
		}
	}





	if (saudymoS == 61) {
		if (zmogausL[pPA + 1][pPB] == '#') {
			pPA++;

			zmogausL[pPA][pPB] = 'x';
			saudymoS = 8;
		}
		else {

			saudymoS = 0;
		}
	}

	if (saudymoS == 71) {
		if (zmogausL[pPA][pPB + 1] == '#') {
			pPB++;

			zmogausL[pPA][pPB] = 'x';
			saudymoS = 7;
		}
		else {

			saudymoS = 0;
		}
	}



}



char Botas::sudekLaivus(int p, int a, int ra)
{
	char A[12][13] =
	{
		" 0123456789",
		"A####--##-#",
		"B---------#",
		"C---#--#---",
		"D---#------",
		"E---#--###-",
		"F----------",
		"G------#---",
		"H----------",
		"K----------",
		"J-#-#----##",
	};

	char B[12][13] =
	{
		" 0123456789",
		"A----#-----",
		"B-#--#--#--",
		"C----------",
		"D----#-----",
		"E-##-#-##--",
		"F----#-----",
		"G-#--#--#--",
		"H-------#--",
		"K----#--#--",
		"J###-------",
	};

	char C[12][13] =
	{
		" 0123456789",
		"A#-##-----#",
		"B----------",
		"C----------",
		"D--###-----",
		"E----------",
		"F----##--##",
		"G----------",
		"H###-------",
		"K----####--",
		"J#--------#",
	};

	char D[12][13] =
	{
		" 0123456789",
		"A--###-----",
		"B-------##-",
		"C-##-------",
		"D----#--##-",
		"E----------",
		"F--####----",
		"G--------#-",
		"H----------",
		"K-----#--#-",
		"J-###------",
	};

	char E[12][13] =
	{
		" 0123456789",
		"A---##-----",
		"B------####",
		"C---##-----",
		"D---------#",
		"E---###----",
		"F---------#",
		"G----#-----",
		"H-#--#----#",
		"K-#--#-----",
		"J---------#",
	};

	char F[12][13] =
	{
		" 0123456789",
		"A-#-----#--",
		"B-------#--",
		"C#---#-----",
		"D#---------",
		"E#--###--#-",
		"F----------",
		"G--#-------",
		"H--#-------",
		"K#-#---##--",
		"J#-#------#",
	};

	char G[12][13] =
	{
		" 0123456789",
		"A###-----##",
		"B----------",
		"C---#---#-#",
		"D---#---#--",
		"E-------#-#",
		"F-------#--",
		"G#---------",
		"H--#-------",
		"K----------",
		"J--##---###",
	};
	if (ra == 0)
	{

		return A[p][a];

	}

	if (ra == 1)
	{

		return B[p][a];

	}

	if (ra == 2)
	{

		return C[p][a];

	}

	if (ra == 3)
	{

		return D[p][a];

	}

	if (ra == 4)
	{

		return E[p][a];

	}


	if (ra == 5)
	{

		return F[p][a];

	}


	if (ra == 6)
	{

		return G[p][a];

	}


}

void Botas::spausdinkZL()
{

	parodoSunaikintus(zmogausL, sunaikinoLaivu);
	if (sunL < sunaikinoLaivu) {
		saudymoS = 0;
		sunL++;
		ss5 = 0;
	}


	for (int i = 0; i < 12; i++)
	{
		cout << "\t";
		for (int j = 0; j < 12; j++)
		{
			cout << zmogausL[i][j];
		}
		cout << endl;
	}

}
