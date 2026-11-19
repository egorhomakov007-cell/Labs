#include <iostream>
#include <clocale>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    int k;
    cout << "Enter k (k>1)" << endl;
    cin >> k;

    // вычисляем граничную точность eps = 10^-k
    double eps = pow(10, -k);

    double x;
    cout << "Enter x" << endl;
    cin >> x;

    // значение, вычисляемое с помощью стандартной функции
    double exact_result = sinh(x);

    // вводим переменную, обозначающую слагаемое
    double term = x;

    // вводим пермеменную для подсчёта факториала в знаменателе
    double m = 3;

    //приближённое значение функции, вычисляемое с помощью ряда Тейлора
    double taylor_result = 0;

    while (abs(term) > eps) {
        taylor_result += term;
        term = (term * x * x) / (m * (m - 1));
        m += 2;
    }
    // переменная для ввода количества цифр после запятой
    int digits;
    cout << "Enter the number of digits" << endl;
    cin >> digits;
    // настройка точности вывода (знаки после запятой)
    cout << fixed << setprecision(digits);

    cout << "Result of function = " << exact_result << endl;
    cout << "Result of Taylor row = " << taylor_result << endl;

    //разница между результатами по модулю
    double diff = abs(exact_result - taylor_result);

    if (diff < eps) {
        cout << "Result of function = result of Taylor series" << endl;
    }
    else if (exact_result > taylor_result) {
        cout << "Result of function > result of Taylor series row" << endl;
    }
    else {
        cout << "Result of function < result of Taylor series" << endl;
    }

    return 0;

}
