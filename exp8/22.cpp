#include <iostream>
using namespace std;

int main() {
    char s[1000]; 
    cin >> s;     
    int len ;

    len = sizeof(s)/sizeof(s[0]);
    cout << len << endl;
    return 0;
}