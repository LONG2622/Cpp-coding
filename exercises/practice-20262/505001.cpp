#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n , c ;
    cin >> n >> c;
    int a[200005];
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    int  l = 1 , r1 = 1, r2 = 1;
    long long ans = 0;
    for(l = 1 ; l <= n ; l ++){
        while(r1 <= n && a[r1] - a[l] <= c){
            r1 ++;
        }
        while(r2 <= n && a[r2] - a[l] < c ){
            r2 ++;
        }
            ans += r1 - r2 ;
    }
    cout << ans;
}