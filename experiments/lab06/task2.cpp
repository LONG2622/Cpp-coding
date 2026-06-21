#include <iostream>
#include <cstring>
using namespace std;

void delchar(char *s1, char s2) {
    int i = 0, j = 0;
    while (s1[i]) {
        if (s1[i] != s2) s1[j++] = s1[i];
        i++;
    }
    s1[j] = '\0';
}

int main() {
    char str[100], ch;
    cin.getline(str, 100);
    cin >> ch;
    delchar(str, ch);
    cout << str << endl;
    return 0;
}