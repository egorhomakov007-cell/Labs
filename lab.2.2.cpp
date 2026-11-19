#include <iostream>
#include <clocale>

using namespace std;

// вычисление произведения элементов массива, расположенных между последним
// максимальным и последним минимальным элементами


int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    const int max_size = 20;

    int size;

    cout << "Enter the size of massive (max = 20)" << endl;
    cin >> size;
    if (size > max_size) {
        cout << "Error" << endl;
        return 0;
    }
    double* arr = new double[size];

    int choice;
    cout << "Do you like to write an each element or to do it randomly?" << endl;
    cout << "1. Random" << endl;
    cout << "2. Own" << endl;
    cin >> choice;

    if (choice == 1) {
        double min;
        double max;
        cout << "Enter the max number" << endl;
        cin >> max;
        cout << "Enter the min number" << endl;
        cin >> min;

        for (int i = 0; i < size; i++) {
            arr[i] = min + (double)rand() / RAND_MAX * (max - min);
        }
        cout << "The original massive:" << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << "Enter " << i + 1 << " " << "element" << endl;
            cin >> arr[i];
        }
    }

    double maximum = arr[0];
    double minimum = arr[0];
    int number_maximum = 0;
    int number_minimum = 0;

    for (int i = 0; i < size;i++) {
        if (arr[i] >= maximum) {
            maximum = arr[i];
            number_maximum = i;
        }
        if (arr[i] <= minimum) {
            minimum = arr[i];
            number_minimum = i;
        }
    }

    double result = 1;


    if (number_minimum < number_maximum) {
        for (int i = number_minimum + 1; i < number_maximum; i++) {
            result *= arr[i];
        }
        cout << "The result of production = " << result << endl;
    }
    else if (number_minimum > number_maximum) {
        for (int i = number_maximum + 1; i < number_minimum; i++) {
            result *= arr[i];
        }
        cout << "The result of production = " << result << endl;
    }
    else {
        cout << "result = 0" << endl; //случай, когда максимум и минимум совпадают (все элементы одинаковы)
    }

delete [] arr;

    return 0;
}
