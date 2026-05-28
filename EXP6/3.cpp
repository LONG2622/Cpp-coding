#include <iostream>
#include <cstring>
using namespace std;

int find(char a[], char ch) {
    for (int i = 0; a[i]; i++)
        if (a[i] == ch) return i + 1;
    return 0;
}

int main() {
    char str[100], ch;
    cin.getline(str, 100);
    cin >> ch;
    cout << find(str, ch) << endl;
    return 0;
}