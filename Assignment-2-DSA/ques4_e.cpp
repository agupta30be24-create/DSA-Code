#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[50] = "HELLO World";
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; 
        }
    }
    cout << "Lowercase string: " << str << endl;
    return 0;
}
