#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);//关闭 cin/cout 和 C 语言 scanf/printf 的同步
→ 关掉后，输入输出速度快 10~100 倍
    cin.tie(nullptr);//加速用的：解开 cin 和 cout 的绑定
→ 默认 cin 输入前会刷新 cout，关掉后更快

    int T ;
    cin >> T;
    for(int i = 0 ; i < T; i++){
        string str;
        cin >> str;
        int K ; 
        cin >> K;
        int left = 0;
        long long ans = 0;
        int cnt[26] = {0};
        for(int right = 0;right < str.size();right++){
            cnt[str[right] - 'a']++;
            while (cnt[ str[right] - 'a' ] > K) {
    	cnt[ str[left] - 'a' ]--;
    	left++;
        }
            ans += right - left + 1;
        }
            cout << ans << endl;
    }
        return 0; 
}