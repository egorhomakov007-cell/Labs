#include <iostream>
#include <clocale>

using namespace std;


// формулу рандом взял у ии

// удаление некоторых элементов массива для получения строго возрастающей последовательности


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
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            for (int k = i; k < size - 1; k++) {
                arr[k] = arr[k + 1];
            }
            i--;
            size--;
        }
    }
    cout << "The final massive:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}
