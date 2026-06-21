#include<iostream>
using namespace std;
int main(){
    int a= 5;
    int b = 3;
    int n = b || a && 0;
    cout << n << endl;
    int m = a < b ? a + 2:b + 2;
    cout << m << endl;
    int p = !(a - b);
    cout << p << endl;
    int x, y ;
    cin >> x >> y;
    cout << x + y << endl;
    int z;
    z = ++a/b--;
    cout << z << endl;
    return 0;
}