#include <iostream>
#include <clocale>
#include <vector>
using namespace std;

int size_1() {
    int rows;
    cout << "Enter the number of rows (<=10)" << endl;
    cin >> rows;
    while (rows > 10 || rows < 1) {
        cout << "Error, repeat please " << endl;
        cin >> rows;
    }
    return rows;
}


int size_2() {
    int cols;
    cout << "Enter the number of cols (<=10)" << endl;
    cin >> cols;
    while (cols > 10 || cols < 1) {
        cout << "Error, repeat please " << endl;
        cin >> cols;
    }
    return cols;
}

vector <vector <int>> vvod(int rows, int cols) {
    vector < vector <int>> matrix(rows, vector <int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter the " << j + 1 << " element of " << i + 1 << " row" << endl;
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void vivod(int rows, int cols, vector < vector <int>> matrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

vector <vector <int>> change_1(int rows, int cols, vector < vector <int>> matrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((i + j) % 2 == 0) {
                matrix[i][j] = 10;
            }
        }
    }
    return matrix;
}

vector <vector <int>> change_2(int rows, int cols, vector < vector <int>> matrix) {
    int  sum1 = 0;
    int sum2 = 0;
    int m;
    for (int n = 0; n < cols; ++n) {
        for (int i = 0; i < cols - 1; ++i) {
            for (int j = 0; j < rows; ++j) {
                sum1 += matrix[j][i];
                sum2 += matrix[j][i + 1];
            }
            if (sum1 > sum2) {
                for (int k = 0; k < rows; ++k) {
                    m = matrix[k][i];
                    matrix[k][i] = matrix[k][i + 1];
                    matrix[k][i + 1] = m;
                }
            }
            sum1 = 0;
            sum2 = 0;
        }
    }
    return matrix;
}

void plus_row(int rows, int cols, vector < vector <int>> matrix) {
    int plus;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            plus = i + 1;
            if (matrix[i][j] < 0) {
                plus = 0;
                break;
            }
        }
        if (plus > 0) {
            cout << "The first row with only positive numbers - " << plus << endl;
            break;
        }
        else if (plus == 0 && i == rows - 1) {
            cout << "No rows with only + elements" << endl;
        }

    }

}

int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    int rows = size_1();

    int cols = size_2();

    vector <vector <int>> matrix = vvod(rows, cols);

    cout << "The first matrix" << endl;
    vivod(rows, cols, matrix);

    matrix = change_1(rows, cols, matrix);

    matrix = change_2(rows, cols, matrix);

    cout << "The final matrix" << endl;
    vivod(rows, cols, matrix);

    plus_row(rows, cols, matrix);

    return 0;
}


