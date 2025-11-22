#include <iostream>
#include <list>
using namespace std;

bool isCircular(list<int> &l) {
    return true;
}

int main() {
    list<int> l = {2, 4, 6, 7, 5};
    cout << (isCircular(l) ? "True" : "False");
}
