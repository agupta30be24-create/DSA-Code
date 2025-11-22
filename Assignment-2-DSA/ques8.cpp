#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int distinct = 0;
    for (int i = 0; i < n; i++)
    {
        int isDuplicate = -1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate==-1)
            distinct++;
    }

    cout << "Total distinct elements: " << distinct << "\n";
    return 0;
}