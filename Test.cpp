#include "doctest.h"

#include <stdexcept>
#include "sources/Fraction.hpp"

Fraction zero(0, 0);

int get_random_int() {
    srand((unsigned) time(NULL));
    return (rand() % (1000 - (-1000) + 1)) + -1000;
}

float get_random_float() {
    srand((unsigned) time(NULL));
    float frc = ((rand() % (1000 - (-1000) + 1)) + -1000) / 1000;
    frc += get_random_int();
    return frc;
}


TEST_CASE("+ operator") {
    SUBCASE("Testing two fraction") {
        Fraction a(5, 3), b(14, 21);
        Fraction ans(7, 3);
        CHECK_EQ(a + b, ans);
        CHECK_EQ(a + b, b + a);

    }
    SUBCASE("Testing fraction and float") {
        Fraction a(5, 3), b(14, 21);
        float f = 2.421;
        Fraction ans(12263, 3000);
        Fraction ans2(9263, 3000);
        CHECK_EQ(a + f, ans);
        CHECK_EQ(b + f, ans2);

    }
    SUBCASE("Testing with zero") {
        Fraction a(5, 3);
        CHECK_EQ(a + 0, a);
        CHECK_EQ(0 + a, a);
        CHECK_EQ(a + Fraction(0, 0), a);

    }
}

TEST_CASE("- operator") {
    SUBCASE("Testing two fraction") {
        Fraction a(5, 3), b(14, 21);

        Fraction ans(1, 1);
        Fraction ans2(-1, 1);

        CHECK_EQ(a - b, ans);
        CHECK_EQ(b - a, ans2);

    }
    SUBCASE("Testing fraction and float") {
        Fraction a(5, 3), b(14, 21);
        float f = 2.5;

        Fraction ans(-5, 6);
        Fraction ans2(-11, 6);

        CHECK_EQ(a - f, ans);
        CHECK_EQ(b - f, ans2);

    }
    SUBCASE("Testing with zero") {
        Fraction a(5, 3);
        CHECK_EQ(a - 0, a);
        CHECK_EQ(a - Fraction(0, 0), a);
    }
}

TEST_CASE("* operator") {
    SUBCASE("Testing two fraction") {
        Fraction a(5, 3), b(14, 21);

        Fraction ans(10, 9);

        CHECK_EQ(a * b, ans);
        CHECK_EQ(a * b, b * a);
    }
    SUBCASE("Testing fraction and float") {
        Fraction a(5, 3), b(14, 21);
        float f = 2.5;

        Fraction ans(25, 6);
        Fraction ans2(5, 3);

        CHECK_EQ(a * f, ans);
        CHECK_EQ(f * b, ans2);
    }
    SUBCASE("Testing with zero") {
        Fraction a(5, 3), b(14, 21);
        CHECK_EQ(a * zero, zero);
        CHECK_EQ(zero * b, zero);
    }
}

TEST_CASE("/ operator") {
    SUBCASE("Testing two fraction") {
        Fraction a(5, 3), b(14, 21);

        Fraction ans(5, 2);
        Fraction ans2(2, 5);

        CHECK_EQ(a / b, ans);
        CHECK_EQ(b / a, ans2);
    }
    SUBCASE("Testing fraction and float") {
        Fraction a(5, 3), b(14, 21);
        float f = 2.5;

        Fraction ans(3, 2);
        Fraction ans2(4, 15);

        CHECK_EQ(f / a, ans);
        CHECK_EQ(b / f, ans2);
    }
    SUBCASE("Cant divide by zero") {
        SUBCASE("Testing make fraction witch is zero") {
            CHECK_NOTHROW(Fraction(0, 123));
            CHECK_NOTHROW(Fraction(0, 0));
            CHECK_THROWS(Fraction(123, 0));
        }
        SUBCASE("Testing divide by zero as fraction") {
            Fraction f1(12, 13);
            Fraction f2(0, 12);
            Fraction f3(0, 13);
            CHECK_THROWS(f1 / f2);
            CHECK_NOTHROW(f2 / f3);
        }
        SUBCASE("Testing divide by zero as float") {
            Fraction f1(12, 13);
            Fraction f2(0, 12);
            CHECK_THROWS(f1 / 0);
            CHECK_NOTHROW(f2 / 0);
        }
    }
}

TEST_CASE("== operator") {
    SUBCASE("Testing two fraction") {
        Fraction a(5, 3), b(14, 21);
        Fraction c(93, 6), d(31, 2);
        Fraction e(4, 3), f(4, 3);

        CHECK_FALSE(a == b);
        CHECK(c == d);
        CHECK(e == f);
        CHECK(Fraction(-4, 2) == Fraction(8, -4));
        CHECK_FALSE(Fraction(2, 2) == Fraction(2, -2));

    }
    SUBCASE("Testing fraction and float") {
        CHECK_FALSE(Fraction(5, 2) == -2.5);
        CHECK(2.5 == Fraction(5, 2));
        CHECK(15.5 == Fraction(93, 6));
    }
}

TEST_CASE("=> operator") {
    SUBCASE("Testing two fraction") {

    }
    SUBCASE("Testing fraction and float") {

    }
}


TEST_CASE("<= operator") {
    SUBCASE("Testing two fraction") {

    }
    SUBCASE("Testing fraction and float") {

    }
}


TEST_CASE("< operator") {
    SUBCASE("Testing two fraction") {

    }
    SUBCASE("Testing fraction and float") {

    }
}


TEST_CASE("> operator") {
    SUBCASE("Testing two fraction") {

    }
    SUBCASE("Testing fraction and float") {

    }
}


TEST_CASE("++ operator") {
    SUBCASE("Testing prefix") {
        Fraction a(12, 41);
        Fraction ans(12, 41);
        Fraction ans2(12 + (41 * 2), 41);
        CHECK_NE(ans, ++a);
        CHECK_EQ(ans2, ++a);
    }
    SUBCASE("Testing postfix") {
        Fraction a(12, 41);
        Fraction ans(12, 41);
        Fraction ans2(12 + (41 * 2), 41);
        CHECK_EQ(ans, a++);
        CHECK_NE(ans2, a++);

    }
}

TEST_CASE("-- operator") {
    SUBCASE("Testing prefix") {
        Fraction a(12, 41);
        Fraction ans(12, 41);
        Fraction ans2(12 - (41 * 2), 41);
        CHECK_NE(ans, --a);
        CHECK_EQ(ans2, --a);
    }
    SUBCASE("Testing postfix") {
        Fraction a(12, 41);
        Fraction ans(12, 41);
        Fraction ans2(12 - (41 * 2), 41);
        CHECK_EQ(ans, a--);
        CHECK_NE(ans2, a--);

    }
}

TEST_CASE("input/out put operator") {
    SUBCASE("Testing fraction") {
        Fraction a(0, 0);
        cout << "please enter two integer" << endl;
        cin >>  a;
        cout << a << endl;


    }
}
