#ifndef LENTA_H
#define LENTA_H


class Lenta
{
public:

	Lenta();
	void parodoSunaikintus(char M[][13], int &sunaik);
	void Spausdink();
	void pasalinkZvaig();

protected:

	char M[12][13] =
	{
			" 0123456789",
			"A----------",
			"B----------",
			"C----------",
			"D----------",
			"E----------",
			"F----------",
			"G----------",
			"H----------",
			"K----------",
			"J----------",
	};

};

#endif // LENTA_H
