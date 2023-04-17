
#include "Fraction.hpp"
#include <cmath>

//-------------help---------------
int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

void reduce(Fraction &frc) {
    if(frc.a == 0){
        frc.b = 0; //just to organize
        return;
    }
    int gcd = GCD(frc.a, frc.b);
    frc.a /= gcd;
    frc.b /= gcd;
}
//-------------constructor---------------
Fraction::Fraction() {
    Fraction(0,0);
}
Fraction::Fraction(int a, int b) : a(a), b(b) {
    if (b == 0 && a != 0)
        throw invalid_argument("cant divide by zero");
}

Fraction::Fraction(float f) {
    a = floor(f * 1000);
    b = 1000;
    reduce(*this);
}


//-------------arithmetic---------------


const Fraction operator+(const Fraction &frc1, const Fraction &frc2) {
    if (frc1.a == 0)return frc2;
    if (frc2.a == 0)return frc1;
    //if same base
    if (frc1.b == frc2.b) {
        return Fraction(frc1.a + frc2.a, frc1.b);
    }
    //if not the same base -> do the cross
    int a = frc1.a * frc2.b + frc2.a * frc1.b;
    int b = frc1.b * frc2.b;

    Fraction temp(a, b);
    reduce(temp);
    return temp;
}

const Fraction operator-(const Fraction &frc1, const Fraction &frc2) {
    Fraction cpy(frc2);
    cpy.a *= -1;
    return frc1 + cpy;
}

const Fraction operator*(const Fraction &frc1, const Fraction &frc2) {
    if (frc1.a == 0 || frc2.a == 0) return Fraction(0, 0);
    Fraction temp(frc1.a * frc2.a, frc1.b * frc2.b);
    reduce(temp);
    return temp;
}

const Fraction operator/(const Fraction &frc1, const Fraction &frc2) {
    if (frc2.a == 0 && frc1.a != 0)
        throw std::invalid_argument("Cant divide by zero");
    Fraction temp(frc1.a * frc2.b, frc1.b * frc2.a);
    reduce(temp);
    return temp;
}

//-------------prefix---------------
Fraction Fraction::operator--() {
    this->a -= this->b;
    return *this;
}

Fraction Fraction::operator++() {
    this->a += this->b;
    return *this;
}

//-------------postfix---------------

const Fraction Fraction::operator--(int) {
    Fraction cpy(*this);
    this->a -= this->b;
    return cpy;
}

const Fraction Fraction::operator++(int) {
    Fraction cpy(*this);
    this->a += this->b;
    return cpy;
}



//-------------comparison---------------


bool operator==(const Fraction &frc1, const Fraction &frc2) {
    Fraction cpy1(frc1);
    Fraction cpy2(frc2);
    reduce(cpy1);
    reduce(cpy2);

    return cpy1.a == cpy2.a && cpy1.b == cpy2.b;
}

bool operator!=(const Fraction &frc1, const Fraction &frc2) {
    return !(frc1 == frc2);
}

bool operator<(const Fraction &frc1, const Fraction &frc2) {
    int gcd = GCD(frc1.b, frc2.b);//common ground
    return (frc1.a * (frc1.b / gcd)) < (frc2.a * (frc2.b / gcd));
}

bool operator>(const Fraction &frc1, const Fraction &frc2) {
    int gcd = GCD(frc1.b, frc2.b);//common ground
    return (frc1.a * (frc1.b / gcd)) > (frc2.a * (frc2.b / gcd));
}

bool operator<=(const Fraction &frc1, const Fraction &frc2) {
    return !(frc1 > frc2);
}

bool operator>=(const Fraction &frc1, const Fraction &frc2) {
    return !(frc1 < frc2);
}

//-------------input,output---------------
ostream &operator<<(ostream &output, const Fraction &frc) {
    return (output << frc.a << "/" << frc.b);
}

istream &operator>>(istream &input, Fraction &frc) {
    input >> frc.a >> frc.b;
    reduce(frc);
    return input;
}


