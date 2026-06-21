//最长上升子序列
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N ; i ++){
        cin >> a[i]; 
    }
    int dp[N] ;
    int ans = 1;
    for(int i = 0; i < N ; i ++){
        for(int j = 0 ; j < i ; j ++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i] , dp[j] + 1); 
            }
        }
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0 ;
}