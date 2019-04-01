#ifndef Rational_H
#define Rational_H

class Rational {
private :
    float numitor, numarator;
public:
    Rational(int i,int j); ///constructor cu parametri
    Rational(const Rational &f1); /// constructor de copiere
    ~Rational();

    int getNumarator();
    int getNumitor();

	Rational& operator==(const Rational &f1);
	Rational& operator*(const Rational &f1);
    Rational& operator*(const int a);
    Rational operator/(const Rational &f1); ///asta stiu ca nu merge dar nu stiu cum sa fac sa mearga amandoua
    Rational operator/(const int a);

    Rational operator^(const Rational &f1);



};

#endif /// multime.H

