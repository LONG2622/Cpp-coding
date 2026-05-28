#include<iostream>
#include<algorithm>
using namespace std;
int cmp(int a , int b){
    return abs(a) > abs(b);
}
int main(){
    int n;
    while(cin >> n && n){
        int a[n];
        for(int  i= 0 ; i < n ;  i++){
            cin >> a[i];
        }
        sort(a , a + n , cmp);
        for(int  i = 0 ; i < n ; i ++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}