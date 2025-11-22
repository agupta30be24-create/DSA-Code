#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> dll = {1, 2, 3, 4, 5};
    list<int> cll = {10, 20, 30, 40};
    cout << "Size of DLL: " << dll.size() << endl;
    cout << "Size of CLL: " << cll.size() << endl;
}
