#include<iostream>
using namespace std;
int huan(int n, int k){
    int survivor = 0 ;
    for(int  i = 2; i <= n ; i ++){
        survivor = (survivor + k ) % i;
    }
    return survivor + 1;
}
int main(){
    int t ;
    cin >> t ;
    for(int i = 1 ; i<= t ; i ++){
        int n  , k;
        cin >> n >> k;
        int ans = huan(n , k);
        cout << "Case" << i << ":"<< ans << endl;
    }
    return 0;
}