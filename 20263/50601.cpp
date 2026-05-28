#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    int a[500] = {0};
    int b[500] = {0};
    int sum = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    } 
    for(int i = 1 ; i <= n ; i++){
        cin >> b[i];
    }
    for(int i = 1 ; i <= n ; i++){
        if(b[a[i]]){
            sum += b[a[i]];
            b[a[i]] = 0;
        }
        else{
            continue;
        }
    }
    cout << sum;
    return 0;
}