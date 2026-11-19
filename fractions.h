#pragma once

class fractions {

private:

    int a; // числитель
    int b; // знаменатель
    void reduction();

public:


    fractions(int m_a, int m_b);

    fractions() = delete;

    fractions(const fractions& others);

    int getA() const;

    int getB() const;

    fractions plus(const fractions& others) const;

    fractions multiply(const fractions& others) const;

    fractions divide(const fractions& others) const;

    void print();




};
