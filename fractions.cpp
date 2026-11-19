#include "fractions.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;


void fractions::reduction() {
    int l_a = abs(a);
    int l_b = abs(b);
    while (l_b != 0) {
        int temp = l_b;
        l_b = l_a % l_b;
        l_a = temp;
    }
    a = a / l_a;
    b = b / l_a;
}

fractions::fractions(int m_a, int m_b) : a(m_a), b(m_b) {
    if (b == 0) {
        throw invalid_argument("Nelzya takoi znamenatel!");
    }
    reduction();
}

fractions::fractions(const fractions& others) : a(others.a), b(others.b) {}

int fractions::getA() const {
    return a;
}

int fractions::getB() const {
    return b;
}

fractions fractions::plus(const fractions& others) const {
    return fractions(a * others.b + others.a * b, b * others.b);
}

fractions fractions::multiply(const fractions& others) const {
    return  fractions(a * others.a, b * others.b);
}

fractions fractions::divide(const fractions& others) const {
    return  fractions(a * others.b, b * others.a);
}

void fractions::print() {
    if ((a > 0 && b < 0) || (a < 0 && b < 0)) {
        a = -a;
        b = -b;
    }
    cout << a << "/" << b << endl;
}

