//George 有一些长度相同的木棍，他把每根木棍随机切成若干段，每段长度 ≤ 50。
//现在他忘了原来有多少根木棍，也忘了原来每根木棍的长度，只知道切完后所有碎段的长度。
//要求：找出原来每根木棍的可能最短长度（整数），
//使得所有碎段可以恰好拼回若干根这种长度的木棍（每根原来长度的木棍，由切出来的若干碎段拼成，每个碎段用一次）。
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int a[65];
bool vis[65];
int len , num;
bool dfs(int cur , int step, int pos){
    if(step == num){
        return true;
    }
    if(cur == len){
        return dfs(0 , step + 1, 0) ;
    }
        int last = -1;
        for(int i = pos; i < n ; i ++){
            if(vis[i] || a[i] == last ){
                continue;
            }
            if(cur + a[i] > len ){
                continue;
            }
            vis[i] = true;
            if(dfs(cur + a[i] ,step , i + 1)){
                return true;
            }
            vis[i] = false;
            last = a[i];
            if(cur == 0 || cur + a[i] == len){
                return false;
            }
        }
        return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n && n){
        int sum = 0 ;
        for(int i = 0 ; i < n ;  i++){
            cin >> a[i] ;
            sum += a[i];
        }
        sort(a ,a+ n);
        reverse(a , a+ n);
        int ans = sum;
        for(len = a[0] ; len <= sum ; len ++){
            if(sum % len != 0){
                continue;
            }
            num = sum / len;
            memset(vis , 0 , sizeof(vis));
            if(dfs(0 , 0 , 0)){
                ans = len ;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}