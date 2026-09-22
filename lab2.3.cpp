#include <iostream>
#include <clocale>

using namespace std;

// Упорядочивание элементов массива с четными номерами по возрастанию

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

    double a;

    for (int i = 3; i < size; i += 2) {
        if (arr[i] < arr[i - 2]) {
            a = arr[i];
            arr[i] = arr[i - 2];
            arr[i - 2] = a;
            for (int k = i - 2; k > 1; k -= 2) {
                if (arr[k] < arr[k - 2]) {
                    a = arr[k];
                    arr[k] = arr[k - 2];
                    arr[k - 2] = a;
                }
                else {
                    break;
                }
            }
        }
    }

    cout << "The final massive: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
