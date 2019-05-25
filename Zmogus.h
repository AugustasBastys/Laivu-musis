#ifndef ZMOGUS_H
#define ZMOGUS_H


class Lenta;
#include "Lenta.h"

class Zmogus : public Lenta
{
public:
	Zmogus();
	int getS();
	char getL(int i, int j);
	void spausdinkB();
	void setBotoL(int i, int j, char c);
	void sauna();
	void dekDvivieti();
	void dekTrivieti();
	void dekKeturvieti();
	void dekVienvieti();


protected:

private:
	int sunaikinoLaivu;
	char botoL[12][13];


};

#endif
