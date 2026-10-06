#include <iostream>
#include <clocale>
#include <limits>

using namespace std;


int _strcspn(const char* string, const char* strCharSet) {
    int length = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        for (int j = 0; strCharSet[j] != '\0'; j++) {
            if (string[i] == strCharSet[j]) {
                return length;
            }
        }
        length++;
    }

    return length;
}


int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    char* string;
    char* strCharSet;

    int size_1;
    int size_2;
    char c;
    int i = 0;

    cout << "Enter the size of your string" << endl;
    cin >> size_1;

    string = new char[size_1 + 1];

    cout << "Enter your string" << endl;
    cin.ignore();

    do {
        if (i == size_1 + 1) {
            break;
        }
        c = cin.get();
        string[i++] = c;
    } while (c != '\n');
    string[--i] = '\0';

    if (c != '\n') {
        cin.ignore(numeric_limits <size_t>::max(), '\n');
    }

    i = 0;

    cout << "Enter the size of forbidden string" << endl;
    cin >> size_2;

    strCharSet = new char[size_2 + 1];

    cout << "Enter your forbidden string" << endl;
    cin.ignore();

    do {
        if (i == size_2 + 1) {
            break;
        }
        c = cin.get();
        strCharSet[i++] = c;
    } while (c != '\n');
    strCharSet[--i] = '\0';

    int length = _strcspn(string, strCharSet);
    cout << "Length = " << length << endl;

    delete[] string;
    delete[] strCharSet;

    return 0;

}
