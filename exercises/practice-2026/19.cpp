#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    int n ;
     cin >> n;
     for(int j = 2 ; j <= n; j+=2){
    for(int i = 2; i <= n; i++){
        if(isprime(i)){
            if(isprime(j - i)){
                cout << j << "=" << i << "+" << j - i << endl;
                break;
            }
        }
    }
}
    return 0;
}