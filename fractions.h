#pragma once

#include <cstdint>
class fractions {

private:

    int64_t a; // числитель
    int64_t b; // знаменатель
    void reduction();

public:


    fractions(int64_t m_a, int64_t m_b);

    fractions() = delete;

    fractions(const fractions& others);

    int64_t getA() const;

    int64_t getB() const;

    fractions plus(const fractions& others) const;

    fractions multiply(const fractions& others) const;

    fractions divide(const fractions& others) const;

    void print();




};
