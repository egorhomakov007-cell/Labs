#include "fractions.h"
#include <iostream>
#include <stdexcept>
using namespace std;


int main() {

    try {
        fractions drob1(6, 0);
        drob1.print();
    }

    catch (const invalid_argument& error) {
        cout << error.what() << endl;
    }

    fractions drob2(6, -32);

    fractions drob3(14, 44);


    fractions drob4 = drob3.multiply(drob2);
    drob4.print();

    fractions drob5 = drob3.divide(drob2);
    drob5.print();

    fractions drob6 = drob3.plus(drob2);
    drob6.print();

    return 0;

}





