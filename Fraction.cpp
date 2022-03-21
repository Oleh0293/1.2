#include "Fraction.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool Fraction::setNum(const int x)
{
    num = x;
    return true;
}

bool Fraction::setDenom(const int x)
{
    if (x)
    {
        denom = x;
        return true;
    }
    else
    {
        denom = 1;
        return false;
    }
}

bool Fraction::Init(const int x, const int y)
{
    return setNum(x) && setDenom(y);
}

void Fraction::Read()
{
    int x;
    int y;

    do {
        cout << "Enter numerator\n"; cin >> x;
        cout << "Enter denominator (must not equal 0)\n"; cin >> y;
    } while (!Init(x, y));
}

void Fraction::Display()
{
    cout << "Numerator = " << num << endl;
    cout << "Denominator = " << denom << endl;
    if (num < 0 && denom < 0 || num == 0)
        cout << setw(3) << abs(num) << endl << "___\n\n"
        << setw(3) << abs(denom) << endl;
    else
    {
        if (num < 0 || denom < 0)
            cout << "  " << setw(3) << abs(num) << endl << "- ___\n\n  "
            << setw(3) << abs(denom) << endl;
        else
            cout << setw(3) << num << endl << "___\n\n"
            << setw(3) << denom << endl;
    }   
}

bool Fraction::Reduce()
{
    int gcd;
    int x = abs(num);
    int y = abs(denom);
    if (x == 0)
    {
        gcd = y;
        denom = denom / gcd;
        return true;
    }
    else
    {
        if (x == 1 || y == 1)
            return false;
        else
        {
            while (x != y)
            {
                x > y ? x -= y : y -= x;
            }
            gcd = x;
        }
    }

    if (gcd == 1)
        return false;
    else
    {
        num = num / gcd;
        denom = denom / gcd;
        return true;
    }
}

double Fraction::Calculate()
{
    return (1. * num / denom);
}