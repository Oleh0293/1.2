#pragma once
class Fraction
{
private:
	int num;
	int denom;
public:
	int getNum      () const   { return num;   };
	int getDenom    () const   { return denom; };
	bool setNum     (const int);
	bool setDenom   (const int);
	bool Init       (const int, const int);
	void Read       ();
	void Display    ();
	bool Reduce     ();
	double Calculate();
};