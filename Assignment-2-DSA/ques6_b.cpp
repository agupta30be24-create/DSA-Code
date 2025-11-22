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
            if (k < s.num && s.e[k].row == i && s.e[k].col == j)
                cout << s.e[k++].val << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

Sparse add(Sparse s1, Sparse s2) {
    if (s1.rows != s2.rows || s1.cols != s2.cols) {
        cout << "Matrices cannot be added!" << endl;
        return {0, 0, 0, nullptr};
    }

    Sparse sum;
    sum.rows = s1.rows;
    sum.cols = s1.cols;
    sum.e = new Element[s1.num + s2.num];

    int i = 0, j = 0, k = 0;
    while (i < s1.num && j < s2.num) {
        if (s1.e[i].row < s2.e[j].row ||
           (s1.e[i].row == s2.e[j].row && s1.e[i].col < s2.e[j].col))
            sum.e[k++] = s1.e[i++];
        else if (s2.e[j].row < s1.e[i].row ||
                (s2.e[j].row == s1.e[i].row && s2.e[j].col < s1.e[i].col))
            sum.e[k++] = s2.e[j++];
        else {
            sum.e[k] = s1.e[i];
            sum.e[k++].val = s1.e[i++].val + s2.e[j++].val;
        }
    }
    while (i < s1.num) sum.e[k++] = s1.e[i++];
    while (j < s2.num) sum.e[k++] = s2.e[j++];

    sum.num = k;
    return sum;
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

    Sparse sum = add(s1, s2);
    cout << "\nAddition Result:\n";
    display(sum);

    return 0;
}
