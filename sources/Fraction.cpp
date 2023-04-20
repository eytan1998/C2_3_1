
#include "Fraction.hpp"


//-------------constructor---------------
Fraction::Fraction() : a(0), b(1) {}

Fraction::Fraction(int a_input, int b_input) {}

Fraction::Fraction(float f) {}


//-------------arithmetic---------------


Fraction operator+(const Fraction &frc1, const Fraction &frc2) {
    return Fraction();
}

Fraction operator-(const Fraction &frc1, const Fraction &frc2) {
    return Fraction();

}

Fraction operator*(const Fraction &frc1, const Fraction &frc2) {
    return Fraction();

}

Fraction operator/(const Fraction &frc1, const Fraction &frc2) {
    return Fraction();

}

//-------------prefix---------------
Fraction Fraction::operator--() {
    return Fraction();

}

Fraction Fraction::operator++() {
    return Fraction();

}

//-------------postfix---------------

const Fraction Fraction::operator--(int) {
    return Fraction();

}

const Fraction Fraction::operator++(int) {
    return Fraction();

}



//-------------comparison---------------


bool operator==(const Fraction &frc1, const Fraction &frc2) {
    return true;
}

bool operator!=(const Fraction &frc1, const Fraction &frc2) {
    return true;
}

bool operator<(const Fraction &frc1, const Fraction &frc2) {
    return true;
}

bool operator>(const Fraction &frc1, const Fraction &frc2) {
    return true;
}

bool operator<=(const Fraction &frc1, const Fraction &frc2) {
    return true;
}

bool operator>=(const Fraction &frc1, const Fraction &frc2) {
    return true;
}

//-------------input,output---------------
ostream &operator<<(ostream &output, const Fraction &frc) {
    return output;
}

istream &operator>>(istream &input, Fraction &frc) {

    return input;
}

