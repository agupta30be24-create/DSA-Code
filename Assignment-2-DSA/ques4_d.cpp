/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    char arr[5][20] = {"banana", "apple", "cherry", "date", "grape"};
    int n = 5;
    char temp[20];

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                swap(arr[i],arr[j]);
            }
        }
    }

    cout << "Part (d) Sorted strings: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}