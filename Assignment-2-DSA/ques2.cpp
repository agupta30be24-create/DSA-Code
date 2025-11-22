#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int temp = 0;
        for(int j = 0; j < n - i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                temp = 1;
            }
        }

        if(temp==0) {
            break;
        }
    }
}

int main() {

    int arr[7] = {64,34,25,12,22,11,90};

    bubbleSort(arr,6);

    cout << "Final array: ";
    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}