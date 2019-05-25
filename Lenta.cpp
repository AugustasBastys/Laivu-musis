#include "pch.h"
#include "Lenta.h"
#include <iostream>



using namespace std;

Lenta::Lenta()
{

}

void Lenta::pasalinkZvaig()
{
	for (int i = 0; i < 12; i++)
	{

		for (int j = 0; j < 12; j++)
		{

			if (M[i][j] == '*')
			{
				M[i][j] = '-';

			}
		}

	}
}

void Lenta::Spausdink()
{
	cout << "\n\n\n";
	for (int i = 0; i < 12; i++)
	{
		cout << "\t";
		for (int j = 0; j < 12; j++)
		{
			cout << M[i][j];
		}
		cout << endl;
	}

}

void Lenta::parodoSunaikintus(char M[][13], int &sunaik)
{

	int iks = 0, dalis = 0;

	for (int i = 1; i < 12; i++)
	{
		for (int j = 1; j < 12; j++)
		{

			if (M[i][j] == 'x' && j != 10)
			{
				iks++;

			}
			else if (M[i][j] == '#')
			{
				dalis++;
			}
			else if (M[i][j] == 'x' && j == 10)
			{

				iks++;

				if (iks == 4 && dalis == 0)
				{

					sunaik++;
					M[i][j] = '$';
					M[i][j - 1] = '$';
					M[i][j - 2] = '$';
					M[i][j - 3] = '$';

				}
				else if (iks == 3 && dalis == 0)
				{

					sunaik++;
					M[i][j - 1] = '$';
					M[i][j - 2] = '$';
					M[i][j] = '$';

				}

				else if (iks == 2 && dalis == 0)
				{

					sunaik++;

					M[i][j - 1] = '$';
					M[i][j] = '$';

				}

				else if (iks == 1 && dalis == 0)
				{

					sunaik++;
					M[i][j] = '$';

				}

				iks = 0;


			}
			else if (M[i][j] != 'x' || j != 10)
			{

				if (iks == 4 && (M[i][j] != '#' || (j == 10)) && dalis == 0)
				{

					sunaik++;
					M[i][j - 1] = '$';
					M[i][j - 2] = '$';
					M[i][j - 3] = '$';
					M[i][j - 4] = '$';


				}
				else if (iks == 3 && (M[i][j] != '#' || (j == 10)) && dalis == 0)
				{

					sunaik++;
					M[i][j - 1] = '$';
					M[i][j - 2] = '$';
					M[i][j - 3] = '$';


				}

				else if (iks == 2 && (M[i][j] != '#' || (j == 10)) && dalis == 0)
				{

					sunaik++;

					M[i][j - 1] = '$';
					M[i][j - 2] = '$';


				}

				else if (iks == 1 && (M[i][j] == '-') && (M[i - 1][j - 1] == '-') && (M[i + 1][j - 1] == '-') && (M[i][j - 2] == '-'))
				{

					sunaik++;
					M[i][j - 1] = '$';

				}


				iks = 0;
			}

			if (M[i][j] == '-') dalis = 0;
		}

	}




	for (int i = 1; i < 12; i++)
	{
		for (int j = 1; j < 12; j++)
		{

			if (M[j][i] == 'x' && j != 10)
			{

				iks++;

			}
			else if (M[j][i] == '#')
			{
				dalis++;
			}
			else if (M[j][i] == 'x' && j == 10)
			{

				iks++;

				if (iks == 4 && dalis == 0)
				{

					sunaik++;
					M[j][i] = '$';
					M[j - 1][i] = '$';
					M[j - 2][i] = '$';
					M[j - 3][i] = '$';

				}
				else if (iks == 3 && dalis == 0)
				{

					sunaik++;
					M[j - 1][i] = '$';
					M[j - 2][i] = '$';
					M[j][i] = '$';

				}

				else if (iks == 2 && dalis == 0)
				{

					sunaik++;

					M[j - 1][i] = '$';
					M[j][i] = '$';

				}

				else if (iks == 1 && (M[j][i - 1] != '#') && (M[j][i + 1] != '#') && (M[j - 1][i] != '#') && (M[j + 1][i] != '#')
					&& ((M[j][i - 1] != 'x') && (M[j][i + 1] != 'x') && (M[j - 1][i] != 'x') && (M[j + 1][i] != 'x'))
					)
				{

					sunaik++;
					M[j][i] = '$';
				}

				iks = 0;

			}
			else if (M[j][i] != 'x' || j != 10)
			{

				if (iks == 4 && (M[j][i] != '#' || (j == 10)) && dalis == 0)
				{

					sunaik++;
					M[j - 1][i] = '$';
					M[j - 2][i] = '$';
					M[j - 3][i] = '$';
					M[j - 4][i] = '$';

				}
				else if (iks == 3 && (M[j][i] != '#' || (j == 10)) && dalis == 0)
				{

					sunaik++;
					M[j - 1][i] = '$';
					M[j - 2][i] = '$';
					M[j - 3][i] = '$';

				}

				else if (iks == 2 && (M[j][i] != '#' || (j == 10)) && dalis == 0)
				{

					sunaik++;

					M[j - 1][i] = '$';
					M[j - 2][i] = '$';

				}

				iks = 0;
			}
			if (M[j][i] == '-') dalis = 0;
		}

	}

	if (M[10][8] == 'x'&&M[10][9] == 'x'&&M[10][10] == 'x') {
		M[10][8] = '$';
		M[10][9] = '$';
		M[10][10] = '$';
		sunaik++;
	}



}
