#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    cout << "Enter the name of input file" << endl;
    string input;
    getline(cin, input);
    cout << endl;

    ifstream fin(input);
    if (!fin.is_open()) {
        cout << "The file is not found" << endl;
        return 1;
    }

    string line;
    cout << "Here is the text of the file:" << endl;
    cout << endl;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.clear();
    fin.seekg(0, ios::beg);

    string last_str;
    vector <string> text;
    vector <int> startLine;
    vector <int> count;
    int i = 1;
    int n = 1;
    bool exist_str = false;
    bool group = false;

    while (getline(fin, line)) {
        if (line == last_str && exist_str) {
            if (group) { //если строка встречается в 3-й и более раз
                n++;
            }
            else { //если строка встречается во 2-й раз
                text.push_back(last_str);
                startLine.push_back(i - 1);
                n++;
                group = true;
            }
        }
        else if (line != last_str && group) {  //когда повторяющиеся строки заканчиваются
            count.push_back(n);
            n = 1;
            group = false;
        }
        last_str = line;
        i++;
        exist_str = true;
    }

    if (n > 1) {
        count.push_back(n); // если строки повторяются в конце файла
    }

    fin.close();

    cout << "Enter the name of output file" << endl;
    string output;
    getline(cin, output);
    cout << endl;

    ofstream fout(output);
    if (!fout.is_open()) {
        cout << "The file is not created" << endl;
        return 1;
    }

    if (!text.empty()) {
        for (size_t i = 0; i < text.size(); i++) {
            fout << "Group " << i + 1 << ":" << endl;
            fout << endl;
            fout << "Start line - " << startLine[i] << endl;
            fout << "Text - " << text[i] << endl;
            fout << "Repetitions - " << count[i] << endl;
            fout << endl;
        }
    }

    fout.close();

    cout << "RESULT: " << endl;
    cout << endl;

    ifstream fin2(output);
    if (!fin2.is_open()) {
        cout << "The file is not found" << endl;
    }
    while (getline(fin2, line)) {
        cout << line << endl;
    }


    fin2.close();

    return 0;
}
