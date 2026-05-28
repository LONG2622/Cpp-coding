#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n ;
     cin >> n;
     int sum = 0;
     for(int i = 3 ; i < n; i++){
        for(int j = i ; j < n; j++){
            if(sqrt(i * i + j * j ) == (int)sqrt(i * i + j * j ) && 
            sqrt(i * i + j * j ) <= n){
                sum++;
            }
        }
     }
        cout << sum;
        return 0;
}