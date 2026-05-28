#include<iostream>
using namespace std;
int main(){
    int m , n , k;
    int sum = 1;
    cin >> m >> n >> k;
    while(n){
        if(n % 2 == 1){
            sum = (m * sum) % k;
        }
        m *= m % k;
        n /= 2;
    }
    cout << sum;
    return 0;
}