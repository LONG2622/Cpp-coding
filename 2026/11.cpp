#include<bits/stdc++.h>
using namespace std;
int fib(int f){
    if(f==0||f==1){
        return 1;
    }
    else{
        return fib(f-1)+fib(f-2);
    }
}
int main(){
    int n ;
    cin >> n;
    cout << fib(n);
    return 0;
}