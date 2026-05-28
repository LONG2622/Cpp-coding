//01背包
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int m , n ;
    cin >> m >> n;
    int dp[n + 1] = {0};
    for(int i = 0; i < n ; i ++){
        int w , v;
        cin >> w >> v;
        for(int j =  m; j >= w; j --){
            dp[j] = max(dp[j] , dp[j - w] + v);
        }
    }
    cout << dp[m] << endl;
    return 0;
}