#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int count = 0;
    for(int i = 0 ; i <= n ; i++){
        while(i){
            if(i % 10 == n){
            count ++;
        }
            i /= 10;
    }
    }
    cout << count ;
    return 0;
}