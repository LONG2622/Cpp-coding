#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;

ll count(ll mid , ll a[]){
    ll cnt =0 ;
    int j = 0;
    for(int i = 0 ; i < n; i ++){
        while(j < n && a[j] - a[i] <= mid){
            j ++;
        }
        cnt += j - i - 1;
    }
    return cnt;
}
int main(){
    cin >> n;
    ll a[n];
    ll ans;
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    sort(a, a + n );
    ll m = ll (n) * (n - 1) / 2;
    ll k = (m+ 1) / 2;
    ll left = 0 , right = a[n - 1] - a[0];
    while(left <= right){
        ll mid = (right + left) / 2;
        if(count(mid , a) >= k){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << ans ;
}