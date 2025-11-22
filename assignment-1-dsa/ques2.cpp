#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 2, 3, 4, 4, 5, 1, 6, 3};
    int n = 10;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
