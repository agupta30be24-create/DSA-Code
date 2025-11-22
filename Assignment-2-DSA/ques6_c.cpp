#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, num;
    Element *e;
};

void display(Sparse s) {
    int k = 0;
    for (int i = 0; i < s.rows; i++) {
        for (int j = 0; j < s.cols; j++) {
            int found = 0;
            for (int x = 0; x < s.num; x++) {
                if (s.e[x].row == i && s.e[x].col == j) {
                    cout << s.e[x].val << " ";
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "0 ";
        }
        cout << endl;
    }
}

Sparse multiply(Sparse s1, Sparse s2) {
    if (s1.cols != s2.rows) {
        cout << "Matrices cannot be multiplied!" << endl;
        return {0, 0, 0, nullptr};
    }

    Sparse result;
    result.rows = s1.rows;
    result.cols = s2.cols;
    result.e = new Element[s1.num * s2.num];
    int k = 0;

    for (int i = 0; i < s1.num; i++) {
        for (int j = 0; j < s2.num; j++) {
            if (s1.e[i].col == s2.e[j].row) {
                result.e[k].row = s1.e[i].row;
                result.e[k].col = s2.e[j].col;
                result.e[k].val = s1.e[i].val * s2.e[j].val;
                k++;
            }
        }
    }
    result.num = k;
    return result;
}

int main() {
    Sparse s1, s2;
    cout << "Enter dimensions of matrix 1: ";
    cin >> s1.rows >> s1.cols;
    cout << "Enter number of non-zero elements: ";
    cin >> s1.num;
    s1.e = new Element[s1.num];
    cout << "Enter row col val:\n";
    for (int i = 0; i < s1.num; i++) cin >> s1.e[i].row >> s1.e[i].col >> s1.e[i].val;

    cout << "\nMatrix 1:\n";
    display(s1);

    cout << "Enter dimensions of matrix 2: ";
    cin >> s2.rows >> s2.cols;
    cout << "Enter number of non-zero elements: ";
    cin >> s2.num;
    s2.e = new Element[s2.num];
    cout << "Enter row col val:\n";
    for (int i = 0; i < s2.num; i++) cin >> s2.e[i].row >> s2.e[i].col >> s2.e[i].val;

    cout << "\nMatrix 2:\n";
    display(s2);

    Sparse product = multiply(s1, s2);
    cout << "\nMultiplication Result:\n";
    display(product);

    return 0;
}
