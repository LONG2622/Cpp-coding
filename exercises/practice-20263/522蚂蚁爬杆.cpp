#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int  t ;
    cin >> t ;
    while(t --){
        int l , n ;
        cin >> l >> n ;
        int e = 0 , las = 0;
        for(int  i = 0 ; i < n ; i++){
            int pos;
            cin >> pos;
            int tl =pos;
            int tr = l - pos;
            e = max(e , min(tl , tr));
            las = max(las , max(tl , tr)); 
        }
        cout << e << " " << las << endl;
    }
    return 0;
}