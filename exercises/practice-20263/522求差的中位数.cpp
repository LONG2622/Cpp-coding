#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll count(ll a[],int n , ll mid){
    ll cnt = 0;
    int j = 0;
    for(int i = 0 ; i < n ; i ++){
        while( j < n && a[j] - a[i] <= mid){
            j ++ ;
        }
        cnt += (j - i - 1);
    }
    return cnt;
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    cin >> n ;
    while(cin >> n){
        ll* a = new ll[n]; 
        for(int  i= 0 ; i <n  ; i++){
            cin >> a[i];
        }
        sort(a , a+ n);
        ll m = (ll) n * (n- 1)/ 2;
        ll k = (m + 1) / 2;
        int l = 0;
        int r = a[n - 1] - a[0] ;
        ll ans = -1;
        while(l <= r){
            ll mid = (r + l)/ 2;
            if(count(a , n , mid) >= k){
                ans =mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}
