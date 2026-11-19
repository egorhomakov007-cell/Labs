#include <iostream>
#include <clocale>

using namespace std;

int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    char string[300];
    char c;
    int i = 0;
    cout << "Enter your string (size is < 300)" << endl;

    do {
        if (i == 300) {
            break;
        }
        c = cin.get();
        string[i++] = c;
    } while (c != '\n');
    string[--i] = '\0';

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ') {
            if (string[i + 1] >= 'a' && string[i + 1] <= 'z') {
                string[i + 1] -= 32; // сдвигаем по таблице ascii на 32 вниз, чтобы буква стала заглавной
            }
        }
    }

    if (string[0] >= 'a' && string[0] <= 'z') {  //отдельно условие для первого слова, т.к перед ним нет пробела
        string[0] -= 32;
    }

    cout << string;

    return 0;

}
