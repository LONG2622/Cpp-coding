#include<iostream>
using namespace std;
int main(){
    int x = 2;
    int b = (-1 < x < 1 );
    int a = !x;
    cout << a << endl;
    cout << b << endl;
    int d = 1 / x;
    cout << d << endl;
    x = 0.75;
    cout << x << endl;
    return 0; 
}