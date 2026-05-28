#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a, int b){
    int temp ;
    if(b){
        temp = b;
        b =  a % b;
        a = temp ;
        return gcd(a, b);
    }
    return a;
}
int main(){
    int a, b;
    cin >> a >> b ;
    cout << gcd(a, b) << endl;
}