#include<iostream>
using namespace std;
bool check(int x){
    int cnt = 0 ;
    int pos = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(a[i] - pos < x) cnt++;
        else pos = a[i];
    }
    return cnt <= m;
}
int d , n , m , a[100010];
int main(){
    cin >> d >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int l = 1 , r = d , ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}