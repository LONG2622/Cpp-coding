#include<iostream>
#include<cmath>
using namespace std;
int arr[500] = {0} ;
void mul(int arr[] , int x){
    arr[499] = 1 ;
    for(int p = 0 ;p < x ;p++ ){
            int carry = 0;
        for(int i = 499 ; i >= 0 ; i --){
            arr[i] = arr[i] * 2 + carry ;
                carry = arr[i] / 10 ;
                arr[i] %= 10 ;
        }
    }
    for(int i = 499; i >= 0; i--) {
        if(arr[i] > 0) {
            arr[i] --;
            break;
        } else {
            arr[i] = 9;  // 借位
        }
    }
}
int main(){
    int n ;
    cin >> n ;
    int digits = floor(n * log10(2)) + 1;
    cout << digits << endl;
    mul( arr , n);
    for(int i  = 0 ; i < 500 ; i++){
        cout << arr[i] ;
        if(i % 50 == 49){
            cout << endl;
        }
    }
}