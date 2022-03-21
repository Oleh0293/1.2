#include <iostream>
#include "Fraction.h"

using namespace std;

Fraction makeFraction(int, int, bool& t);

int main()
{
	Fraction z;
	z.Read();
	z.Display();
	cout << "Fraction reduction...\n";
	z.Reduce();
	z.Display();
	cout << "Fraction = " << z.Calculate() << endl;

	int x, y;
	bool t = true;
	cout << "numerator: "  ;  cin >> x;
	cout << "denuminator: ";  cin >> y;
	z = makeFraction(x, y, t);
	if (!t)
	{
		cerr << "ERROR: division by zero.";
		return -1;
	}
	z.Display();
	cout << "Fraction reduction...\n";
	z.Reduce();
	z.Display();
	cout << "Fraction = " << z.Calculate() << endl;
}

Fraction makeFraction(int x, int y, bool& t)
{
	Fraction z;
	if (!z.Init(x, y))
	{
		cout << "ERROR: wrong arguments. ";
		t = false;
	}

	return z;
}