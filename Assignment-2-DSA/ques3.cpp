#include <iostream>
using namespace std;

// (a) using Linear time
int missingLinear(int arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		if (arr[i+1] - arr[i] != 1) return arr[i]+1;
	}
	return -1;
}

// (b) using Binary search
int missbinary(int arr[], int n) {
	int start=0, end=n-1;
	while(start<=end) {
		int mid=(start+end)/2;
		if(arr[mid]!=mid+1) end=mid-1;
		else start=mid+1;
	}
	return start+1;
}

int main() {
	int arr[]= {1,2,3,4,6,7,8};
	int n=7;
	cout<<"Missing (Linear): "<<missingLinear(arr,n)<<endl;
	cout<<"Missing (Binary): "<<missbinary(arr,n)<<endl;
}
