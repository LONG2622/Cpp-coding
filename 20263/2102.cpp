#include<iostream>
using namespace std;
int main(){
    int n ;
     cin >> n;
    int ma = 0;
    while(n --){
        int m ; 
        cin >> m;
        int sum = 0;
        while(m){
            sum += m % 10;
            m /= 10;
        }
        if(sum > ma){
            ma = sum;
        }
    }
    cout << ma;
    return 0;
}