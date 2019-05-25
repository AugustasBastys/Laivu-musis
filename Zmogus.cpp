#include "pch.h"
#include "Zmogus.h"
#include "Lenta.h"
#include <iostream>
#include <windows.h>
#include <MMSystem.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <string>


using namespace std;

int stringToInt(string s)
{
	int sk;

	if (s == "0") sk = 0;
	else if (s == "1") sk = 1;
	else if (s == "2") sk = 2;
	else if (s == "3") sk = 3;
	else if (s == "4") sk = 4;
	else if (s == "5") sk = 5;
	else if (s == "6") sk = 6;
	else if (s == "7") sk = 7;
	else if (s == "8") sk = 8;
	else if (s == "9") sk = 9;
	else sk = 54;

	return sk;
}

int raideISk(string s)
{
	int sk;

	if (s == "a" || s == "A") sk = 0;
	else if (s == "b" || s == "B") sk = 1;
	else if (s == "c" || s == "C") sk = 2;
	else if (s == "d" || s == "D") sk = 3;
	else if (s == "e" || s == "E") sk = 4;
	else if (s == "f" || s == "F") sk = 5;
	else if (s == "g" || s == "G") sk = 6;
	else if (s == "h" || s == "H") sk = 7;
	else if (s == "k" || s == "K") sk = 8;
	else if (s == "j" || s == "J") sk = 9;
	else sk = 54;

	return sk;
}

Zmogus::Zmogus()
{
	sunaikinoLaivu = 0;
}

int Zmogus::getS()
{
	return sunaikinoLaivu;
}

char Zmogus::getL(int i, int j)
{
	return M[i][j];
}

void Zmogus::spausdinkB()
{

	parodoSunaikintus(botoL, sunaikinoLaivu);


	for (int i = 0; i < 11; i++)
	{
		cout << "\t";
		for (int j = 0; j < 11; j++)
		{
			if (botoL[i][j] != '#')
				cout << botoL[i][j];
			else cout << "-";
		}
		cout << endl;
	}

}

void Zmogus::setBotoL(int i, int j, char c)
{
	botoL[i][j] = c;
}

void Zmogus::sauna()
{
	string r;
	int sk;

	while (1) {

		cout << "\nsaudykite [pirma raide o poto sk iveskite], \nbotas saudys i pirma, o jus saudysite i antra lenta" << endl;
		cin >> r >> sk;

		if (r.length() == 1) {
			if ((raideISk(r) > -1 && raideISk(r) < 10) && (sk > -1 && sk < 10)) {
				break;
			}
		}

	}
	if (botoL[raideISk(r) + 1][sk + 1] == '-') botoL[raideISk(r) + 1][sk + 1] = '.';
	if (botoL[raideISk(r) + 1][sk + 1] == '#')
	{
		botoL[raideISk(r) + 1][sk + 1] = 'x';
		if (
			(botoL[raideISk(r) + 1][sk + 2] != 'x' && botoL[raideISk(r) + 1][sk + 2] != '#') &&
			(botoL[raideISk(r) + 1][sk] != 'x' && botoL[raideISk(r) + 1][sk] != '#') &&
			(botoL[raideISk(r)][sk + 1] != 'x' && botoL[raideISk(r)][sk + 1] != '#') &&
			(botoL[raideISk(r) + 2][sk + 1] != 'x' && botoL[raideISk(r) + 2][sk + 1] != '#')
			)
		{
			sunaikinoLaivu++;
			botoL[raideISk(r) + 1][sk + 1] = '$';
		}
	}

}

void Zmogus::dekDvivieti()
{
	while (true)
	{

		int e, e1, e2, sk, pasirinkimai[3];
		string c, s, s1, s2;


		cout << "dekite dvivieti laiveli (pirma pasirinkite vertikaliai arba horizontaliai [v] [h])\n";
		cin >> c;

		if (c == "h")
		{
			cout << "pasirinkite eilute \n";
			cin >> s;
			cout << "taigi db pasirinkite kur deti\n";
			cin >> e1 >> e2;

			pasirinkimai[0] = e1;
			pasirinkimai[1] = e2;


			sort(pasirinkimai, pasirinkimai + 2);

			bool teisingaiIsrinkoSk = false;

			if (pasirinkimai[1] - pasirinkimai[0] == 1)
			{
				teisingaiIsrinkoSk = true;
			}

			sk = raideISk(s);

			if ((sk >= 0 && sk < 10) && teisingaiIsrinkoSk)
			{

				if ((M[sk + 1][e1 + 1] == '-'&&
					M[sk + 1][e2 + 1] == '-') && (M[sk + 1][e1 + 1] != '*'&&
						M[sk + 1][e2 + 1] != '*'))
				{

					M[sk + 1][e1 + 1] = '#';
					M[sk + 1][e2 + 1] = '#';


					for (int i = sk; i < sk + 3; i++)
					{
						for (int j = e1; j < e1 + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = sk; i < sk + 3; i++)
					{
						for (int j = e2; j < e2 + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}


					break;
				}
			}
		}
		else if (c == "v")
		{

			cout << "pasirinkite stulpeli \n";
			cin >> e;
			cout << "taigi db pasirinkite kur deti\n";
			cin >> s1 >> s2;

			e1 = raideISk(s1);
			e2 = raideISk(s2);


			pasirinkimai[0] = e1;
			pasirinkimai[1] = e2;


			sort(pasirinkimai, pasirinkimai + 2);

			bool teisingaiIsrinkoSk = false;

			if (pasirinkimai[1] - pasirinkimai[0] == 1)
			{
				teisingaiIsrinkoSk = true;
			}



			if ((e >= 0 && e < 10) && teisingaiIsrinkoSk)
			{

				if ((M[e1 + 1][e + 1] == '-'&&
					M[e2 + 1][e + 1] == '-'
					) && (M[e1 + 1][e + 1] != '*'&&
						M[e2 + 1][e + 1] != '*'
						))
				{

					M[e1 + 1][e + 1] = '#';
					M[e2 + 1][e + 1] = '#';



					for (int i = e1; i < e1 + 3; i++)
					{
						for (int j = e; j < e + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = e2; i < e2 + 3; i++)
					{
						for (int j = e; j < e + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}
					break;
				}
			}

		}

	}
}

void Zmogus::dekTrivieti()
{
	while (true)
	{

		int e, e1, e2, e3, sk, sum = 0, pasirinkimai[3];
		string c, s, s1, s2, s3;


		cout << "dekite trivieti laiveli (pirma pasirinkite vertikaliai arba horizontaliai [v] [h])\n";
		cin >> c;

		if (c == "h")
		{
			cout << "pasirinkite eilute \n";
			cin >> s;
			cout << "taigi db pasirinkite kur deti\n";
			cin >> e1 >> e2 >> e3;

			pasirinkimai[0] = e1;
			pasirinkimai[1] = e2;
			pasirinkimai[2] = e3;

			sort(pasirinkimai, pasirinkimai + 3);

			bool teisingaiIsrinkoSk = false;

			if (pasirinkimai[2] - pasirinkimai[1] == 1)
			{
				if (pasirinkimai[2] - pasirinkimai[0] == 2)
				{
					teisingaiIsrinkoSk = true;
				}
			}

			sk = raideISk(s);

			if ((sk >= 0 && sk < 10) && teisingaiIsrinkoSk)
			{

				if ((M[sk + 1][e1 + 1] == '-'&&
					M[sk + 1][e2 + 1] == '-'&&
					M[sk + 1][e3 + 1] == '-') && (M[sk + 1][e1 + 1] != '*'&&
						M[sk + 1][e2 + 1] != '*'&&
						M[sk + 1][e3 + 1] != '*'))
				{

					M[sk + 1][e1 + 1] = '#';
					M[sk + 1][e2 + 1] = '#';
					M[sk + 1][e3 + 1] = '#';

					for (int i = sk; i < sk + 3; i++)
					{
						for (int j = e1; j < e1 + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = sk; i < sk + 3; i++)
					{
						for (int j = e2; j < e2 + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = sk; i < sk + 3; i++)
					{
						for (int j = e3; j < e3 + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}
					break;
				}
			}
		}
		else if (c == "v")
		{

			string stulp = "";
			while (1) {
				cout << "pasirinkite stulpeli \n";
				cin >> stulp;

				if (stulp == "0" || stulp == "1" || stulp == "2" || stulp == "3" || stulp == "4" || stulp == "5" ||
					stulp == "6" || stulp == "7" || stulp == "8" || stulp == "9")
				{
					e = stringToInt(stulp);
					break;

				}



			}

			cout << "taigi db pasirinkite kur deti\n";
			cin >> s1 >> s2 >> s3;

			e1 = raideISk(s1);
			e2 = raideISk(s2);
			e3 = raideISk(s3);

			pasirinkimai[0] = e1;
			pasirinkimai[1] = e2;
			pasirinkimai[2] = e3;

			sort(pasirinkimai, pasirinkimai + 3);

			bool teisingaiIsrinkoSk = false;

			if (pasirinkimai[2] - pasirinkimai[1] == 1)
			{
				if (pasirinkimai[2] - pasirinkimai[0] == 2)
				{
					teisingaiIsrinkoSk = true;
				}
			}


			if ((e >= 0 && e < 10) && teisingaiIsrinkoSk)
			{

				if ((M[e1 + 1][e + 1] == '-'&&
					M[e2 + 1][e + 1] == '-'&&
					M[e3 + 1][e + 1] == '-'
					) && (M[e1 + 1][e + 1] != '*'&&
						M[e2 + 1][e + 1] != '*'&&
						M[e3 + 1][e + 1] != '*'
						))
				{

					M[e1 + 1][e + 1] = '#';
					M[e2 + 1][e + 1] = '#';
					M[e3 + 1][e + 1] = '#';


					for (int i = e1; i < e1 + 3; i++)
					{
						for (int j = e; j < e + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = e2; i < e2 + 3; i++)
					{
						for (int j = e; j < e + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = e3; i < e3 + 3; i++)
					{
						for (int j = e; j < e + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					break;
				}
			}

		}

	}
}

void Zmogus::dekKeturvieti()
{
	while (true)
	{

		int e, e1, e2, e3, e4, sk, sum = 0, pasirinkimai[4];
		string c, s, s1, s2, s3, s4;


		cout << "dekite keturvieti laiveli (pirma pasirinkite vertikaliai arba horizontaliai [v] [h])\n";
		cin >> c;

		if (c == "h")
		{
			cout << "pasirinkite eilute \n";
			cin >> s;
			cout << "taigi db pasirinkite kur deti\n";
			cin >> e1 >> e2 >> e3 >> e4;

			pasirinkimai[0] = e1;
			pasirinkimai[1] = e2;
			pasirinkimai[2] = e3;
			pasirinkimai[3] = e4;

			sort(pasirinkimai, pasirinkimai + 4);

			bool teisingaiIsrinkoSk = false;

			if (pasirinkimai[3] - pasirinkimai[2] == 1)
			{
				if (pasirinkimai[3] - pasirinkimai[1] == 2)
				{
					if (pasirinkimai[3] - pasirinkimai[0] == 3)
					{
						teisingaiIsrinkoSk = true;
					}
				}
			}

			sk = raideISk(s);

			if ((sk >= 0 && sk < 10) && teisingaiIsrinkoSk)
			{

				if ((M[sk + 1][e1 + 1] == '-'&&
					M[sk + 1][e2 + 1] == '-'&&
					M[sk + 1][e3 + 1] == '-'&&
					M[sk + 1][e4 + 1] == '-') && (M[sk + 1][e1 + 1] != '*'&&
						M[sk + 1][e2 + 1] != '*'&&
						M[sk + 1][e3 + 1] != '*'&&
						M[sk + 1][e4 + 1] != '*'))
				{


					M[sk + 1][e1 + 1] = '#';
					M[sk + 1][e2 + 1] = '#';
					M[sk + 1][e3 + 1] = '#';
					M[sk + 1][e4 + 1] = '#';

					for (int i = sk; i < sk + 3; i++)
					{
						for (int j = e1; j < e1 + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = sk; i < sk + 3; i++)
					{
						for (int j = e2; j < e2 + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = sk; i < sk + 3; i++)
					{
						for (int j = e3; j < e3 + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = sk; i < sk + 3; i++)
					{
						for (int j = e4; j < e4 + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}
					break;
				}
			}
		}
		else if (c == "v")
		{

			cout << "pasirinkite stulpeli \n";
			cin >> e;
			cout << "taigi db pasirinkite kur deti\n";
			cin >> s1 >> s2 >> s3 >> s4;

			e1 = raideISk(s1);
			e2 = raideISk(s2);
			e3 = raideISk(s3);
			e4 = raideISk(s4);

			pasirinkimai[0] = e1;
			pasirinkimai[1] = e2;
			pasirinkimai[2] = e3;
			pasirinkimai[3] = e4;

			sort(pasirinkimai, pasirinkimai + 4);

			bool teisingaiIsrinkoSk = false;

			if (pasirinkimai[3] - pasirinkimai[2] == 1)
			{
				if (pasirinkimai[3] - pasirinkimai[1] == 2)
				{
					if (pasirinkimai[3] - pasirinkimai[0] == 3)
					{
						teisingaiIsrinkoSk = true;
					}
				}
			}




			if ((e >= 0 && e < 10) && teisingaiIsrinkoSk)
			{

				if ((M[e1 + 1][e + 1] == '-'&&
					M[e2 + 1][e + 1] == '-'&&
					M[e3 + 1][e + 1] == '-'&&
					M[e4 + 1][e + 1] == '-') && (M[e1 + 1][e + 1] != '*'&&
						M[e2 + 1][e + 1] != '*'&&
						M[e3 + 1][e + 1] != '*'&&
						M[e4 + 1][e + 1] != '*'))
				{

					M[e1 + 1][e + 1] = '#';
					M[e2 + 1][e + 1] = '#';
					M[e3 + 1][e + 1] = '#';
					M[e4 + 1][e + 1] = '#';

					for (int i = e1; i < e1 + 3; i++)
					{
						for (int j = e; j < e + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = e2; i < e2 + 3; i++)
					{
						for (int j = e; j < e + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = e3; i < e3 + 3; i++)
					{
						for (int j = e; j < e + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}

					for (int i = e4; i < e4 + 3; i++)
					{
						for (int j = e; j < e + 3; j++)
						{
							if (M[i][j] == '-')
							{
								M[i][j] = '*';
							}
						}
					}
					break;
				}
			}

		}


	}
}

void Zmogus::dekVienvieti()
{
	int sk, a;
	string c;



	while (true)
	{
		cout << "dekite vienvieti laiva (pirma rasom raide o poto sk)\n";
		cin >> c >> a;

		sk = raideISk(c);

		if (((sk >= 0 && sk < 10) && (a >= 0 && a < 10)))
		{

			if (M[sk + 1][a + 1] != '#' && M[sk + 1][a + 1] != '*')
			{
				M[sk + 1][a + 1] = '#';

				for (int i = sk; i < sk + 3; i++)
				{
					for (int j = a; j < a + 3; j++)
					{
						if (M[i][j] == '-')
						{
							M[i][j] = '*';
						}
					}
				}
				break;
			}
		}
	}
}
#include "pch.h"