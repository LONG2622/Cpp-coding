#include<iostream>
#include<cstring>
using namespace std;
const int MA = 20;
int n ;
int  res[MA];
bool vis[MA];
bool isprime[40];
void initprime(){
    memset(isprime ,true ,sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for(int i = 0 ; i * i < 40 ;i++){
        if(isprime[i]){
            for(int j = i * i ;j < 40; j += i){
                isprime[j] = false;
            }
        }
    }
}
void dfs(int pos){
    if(pos == n){
        if(isprime[res[pos - 1]+res[0]]){
            for(int i = 0 ; i< n ;i++){
                if(i == 0){
                    cout << res[i];
                }
                else{
                    cout << " " << res[i];
                }
            }
            cout << endl;
        }
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!vis[i] && isprime[res[pos-1] + i]) {
            vis[i] = true;
            res[pos] = i;
            dfs(pos + 1);
            vis[i] = false; // 回溯
        }
    }
}
int main(){
    initprime();
    int cas = 1;
    while (cin >> n) {
        memset(vis, false, sizeof(vis));
        memset(res, 0, sizeof(res));
        res[0] = 1;   // 第一个数固定是 1
        vis[1] = true;
        cout << "Case " << cas++ << ":" << endl;
        // 奇数（除了1）一定无解（奇偶相加才是素数，环必须偶数）
        if (n % 2 == 0 || n == 1) {
            dfs(1);
        }
        cout << endl; // 每组后空行
    }
    return 0;
}