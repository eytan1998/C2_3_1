

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

namespace ariel {}

class Fraction {
    int a;
    int b;
public:
    //-------------constructor---------------

    explicit Fraction();

    Fraction(int a, int b);

    Fraction(float f);

    //-------------arithmetic---------------

    friend Fraction operator+(const Fraction &frc1, const Fraction &frc2);

    friend Fraction operator-(const Fraction &frc1, const Fraction &frc2);

    friend Fraction operator*(const Fraction &frc1, const Fraction &frc2);

    friend Fraction operator/(const Fraction &frc1, const Fraction &frc2);

//-------------prefix---------------

    Fraction operator++();

    Fraction operator--();

    //-------------postfix---------------


    const Fraction operator++(int);

    const Fraction operator--(int);

    //-------------comparison---------------


    friend bool operator==(const Fraction &c1, const Fraction &c2);

    friend bool operator!=(const Fraction &c1, const Fraction &c2);

    friend bool operator<(const Fraction &c1, const Fraction &c2);

    friend bool operator>(const Fraction &c1, const Fraction &c2);

    friend bool operator<=(const Fraction &c1, const Fraction &c2);

    friend bool operator>=(const Fraction &c1, const Fraction &c2);

    //-------------input,output---------------


    friend ostream &operator<<(ostream &output, const Fraction &frc);

    friend istream &operator>>(istream &input, Fraction &frc);


};

#endif //FRACTION_H