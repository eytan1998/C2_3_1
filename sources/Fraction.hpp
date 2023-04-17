

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

namespace ariel{}

class Fraction {
    int a;
    int b;
public:
    Fraction();
    Fraction(int a, int b);
    Fraction(float f);

    friend void reduce(Fraction &frc);

    friend const Fraction operator+ (const Fraction& frc1, const Fraction& frc2);

    friend const Fraction operator- (const Fraction& frc1, const Fraction& frc2);

    friend const Fraction operator* (const Fraction& frc1, const Fraction& frc2);

    friend const Fraction operator/ (const Fraction& frc1, const Fraction& frc2);


    Fraction operator++();
    const Fraction operator++(int);
    Fraction operator--();
    const Fraction operator--(int);

    friend bool operator==(const Fraction &c1, const Fraction &c2);

    friend bool operator!=(const Fraction &c1, const Fraction &c2);

    friend bool operator<(const Fraction &c1, const Fraction &c2);

    friend bool operator>(const Fraction &c1, const Fraction &c2);

    friend bool operator<=(const Fraction &c1, const Fraction &c2);

    friend bool operator>=(const Fraction &c1, const Fraction &c2);


    friend ostream &operator<<(ostream &output, const Fraction &frc);

    friend istream &operator>>( istream  &input, Fraction &frc );


};
#endif //FRACTION_H
