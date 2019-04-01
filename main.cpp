#include <iostream>
#include <math.h>
#include "Rational.h"

using namespace std;
/*
2. Clasa pentru un numar rational, care sa ofere urmatoarele functionalitati:
● metoda interna pentru simplificare; numerele se vor memora in forma canonica
(numaratorul si numitorul sa fie prime intre ele, numitorul > 0);
● supraincarcarea operatorului ==, pentru testarea egalitatii a doua numere rationale;

*/
///constructor de copiere;
Rational::Rational(const Rational &f1)
{
        numarator=f1.numarator;
        numitor=f1.numitor;
}

///constructor standard cu parametri;
Rational::Rational (int i, int j)
{
    numarator = i;
    numitor = j;
}
///destructor;
Rational::~Rational()
{
    numarator = 0;
    numitor = 0;
}

/// obtinere numaratorului;
int Rational::getNumarator()
{
    return numarator;
}

/// obtinerea numitorului.
int Rational::getNumitor()
{
    return numitor;
}

///● supraincarcarea operatorului ==, pentru testarea egalitatii a doua numere rationale;
Rational& Rational::operator== (const Rational &f1)
{
    int k = 0;

    if (numitor == f1.numitor && numarator == f1.numarator) {
        k = 1;
    }

    if (k == 1) {
        cout<<"SUNT EGALE"<<"\n";
    } else {
        cout<<"NU SUNT EGALE"<<"\n";
    }
}

/// ● supraincarcarea operatorului * pentru inmultirea a doua numere rationale;
Rational& Rational::operator* (const Rational &f1)
{
    numarator = numarator * f1.numarator;
    numitor = numitor * f1.numitor;
    return *this;
}

/// ● supraincarcarea operatorului * pentru inmultirea unui numar rational cu un intreg;
Rational& Rational::operator* (const int a)
{
    numarator = a * numarator;
    numitor = numitor;
    return *this;
}

/// ● supraincarcarea operatorului / pentru impartirea a doua numere rationale
Rational Rational::operator/(const Rational &f1)
{
        return Rational(numarator * f1.numitor, numitor * f1.numarator);
}

/// ● supraincarcarea operatorului / pentru impartirea unui numar rational cu un intreg;
Rational Rational::operator/(const int a)
	{
        return Rational(numarator, numitor * a);
    }


/// ● supraincarcarea operatorului ^ pentru ridicarea la putere naturala a unui numar rational;
Rational Rational::operator^(const Rational &f1)
{
        int a = 3;
	    numitor = pow(f1.numitor, a);
        numarator = pow(f1.numarator, a);
        return Rational(f1.numarator, f1.numitor);
}


int main()
{
    Rational q(2, 3);
    Rational b(2, 3);
    Rational c(1, 1);
    q==b; /// SUNT EGALE
    q==c; /// NU SUNT EGALE

    Rational f(2, 4); /// 2 4
    cout<<"f = "<<f.getNumarator()<<" "<<f.getNumitor()<<"\n";


    Rational g(3, 5); /// 3 5
    cout<<"g = "<<g.getNumarator()<<" "<<g.getNumitor()<<"\n";


    Rational h(1, 1); /// 6 20
    h = f * g;  /// (2*3)/(4*5)
    cout<<"h = g * f = "<<h.getNumarator()<<" "<<h.getNumitor()<<"\n";


    int a = 3;
    Rational t(1, 1); /// 18 20
    t = h * a;        ///(6*3)/20
    cout<<"t = h * a = "<<t.getNumarator()<<" "<<t.getNumitor()<<"\n";


    Rational d(5, 4); /// 36 35
    Rational x(9, 7);
    d = x / d;        /// (9*4)/(5*7)
    cout<<"d = x / d = "<<d.getNumarator()<<" "<<d.getNumitor()<<"\n";


    a=5;
    Rational v(15, 10); ///15 50
    v = v / a;          /// 15/(10*5)
    cout<<"v = v / a = "<<v.getNumarator()<<" "<<v.getNumitor()<<"\n";


    Rational j(2, 2); /// a=3 rezultat: 8 8
    j = j ^ j;        /// (2*2*2)/(2*2*2)
    cout<<"j = j ^ j = "<<j.getNumarator()<<" "<<j.getNumitor()<<"\n";

    return 0;
}
