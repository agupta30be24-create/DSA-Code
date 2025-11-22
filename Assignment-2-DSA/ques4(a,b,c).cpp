#include <iostream>
#include <cstring>   
using namespace std;

bool isVowel(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}


int main() {
    char str1[50] = "abc";   
    char str2[50] = "def";   
    char str3[100];

    int len1 = strlen(str1);
    int len2 = strlen(str2);
// (a) To concatenate two strings
    for (int i = 0; i < len1; i++) {
        str3[i] = str1[i];
    }

    for (int j = 0; j < len2; j++) {
        str3[len1 + j] = str2[j];
    }

    str3[len1 + len2] = '\0';
    
    cout << "Concatenated string: " << str3 << endl;
    
    int len3 = strlen(str3);
// (b) To reverse a string
    for (int i = 0; i < len3 / 2; i++) {
        char temp = str3[i];
        str3[i] = str3[len3 - i - 1];
        str3[len3 - i - 1] = temp;
    }
    cout << "Reversed string (str3): " << str3 << endl;
    
    
// (c) Delete all vowels from string
    char noVowel[50];
    int k = 0;
    for (int i = 0; i < len3; i++) {
        if (!isVowel(str3[i])) {
            noVowel[k++] = str3[i];
        }
    }
    noVowel[k] = '\0';
    cout << "Without vowels string: " << noVowel << endl;
    return 0;
}
