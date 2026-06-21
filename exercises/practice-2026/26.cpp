#include<iostream>
using namespace std;
int main(){
    int h , min ,s;
    cin >> h >> min >> s;
    char c;
    cin >> c;
    int sum = 0;
    if(c == 'P'){
        h += 12;
    }
    sum += h * 3600 + min * 60 + s;
    cout << sum << endl;
    return 0;
}