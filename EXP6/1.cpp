 #include <iostream>
#include <cstring>
using namespace std;

void delchar(char *s1, char s2) {
    if (*s1 == '\0') return;
    if (*s1 == s2) {
        strcpy(s1, s1 + 1);
        delchar(s1, s2);
    } else delchar(s1 + 1, s2);
}

int main() {
    char str[100], ch;
    cin.getline(str, 100);
    cin >> ch;
    delchar(str, ch);
    cout << str << endl;
    return 0;
}