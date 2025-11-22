#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> cll = {20, 100, 40, 80, 60};
    for (int x : cll) cout << x << " ";
    cout << *cll.begin() << endl;
}
