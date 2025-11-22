#include <iostream>
#include <list>
using namespace std;

int main() {
    list<char> l = {'l', 'e', 'v', 'e', 'l'};
    auto f = l.begin();
    auto b = --l.end();
    bool flag = true;
    while (f != b && next(f) != b) {
        if (*f != *b) {
            flag = false;
            break;
        }
        ++f;
        --b;
    }
    cout << (flag ? "True" : "False");
}
