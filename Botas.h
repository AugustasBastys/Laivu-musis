#ifndef BOTAS_H
#define BOTAS_H

class Lenta;
#include "Lenta.h"

class Botas : public Lenta
{
public:
	Botas();
	void setZL(int i, int j, char c);
	int getS();
	void saudo();
	char sudekLaivus(int p, int a, int ra);
	void spausdinkZL();



protected:

	char zmogausL[12][13];
	int sunaikinoLaivu;

private:
	int pataikeA, pataikeB, saudymoS, sS2, sS3, pPA, pPB, sunL, ss5;
};

#endif
