#include <iostream>
using namespace std;

struct Triplet {
    int row;
    int col;
    int value;
};
void sortTriplets(Triplet arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].row > arr[j + 1].row || 
               (arr[j].row == arr[j + 1].row && arr[j].col > arr[j + 1].col)) {
                Triplet temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int ROWS = 4;
    const int COLS = 5;
    
    int sparseMatrix[ROWS][COLS] = {
        {0, 0, 1, 0, 2},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 8, 0},
        {0, 2, 0, 0, 0}
    };
    Triplet trip[ROWS * COLS];
    int count = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (sparseMatrix[i][j] != 0) {
                trip[count].row = i;
                trip[count].col = j;
                trip[count].value = sparseMatrix[i][j];
                count++;
            }
        }
    }
    
    for (int i = 0; i < count; i++) {
        cout  << trip[i].row << ", "
             << trip[i].col << ", "
             << trip[i].value <<endl;
    }
    Triplet transposedTriplets[ROWS * COLS];
    for (int i = 0; i < count; i++) {
        transposedTriplets[i].row = trip[i].col;
        transposedTriplets[i].col = trip[i].row;
        transposedTriplets[i].value = trip[i].value;
    }
    sortTriplets(transposedTriplets,count);
    cout<<endl<<"transposed Triplet\n";
    for (int i = 0; i < count; i++) {
        cout << transposedTriplets[i].row << ", "
             << transposedTriplets[i].col << ", "
             << transposedTriplets[i].value <<endl;
    }
    return 0;
}

