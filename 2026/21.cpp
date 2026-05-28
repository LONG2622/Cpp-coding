#include<iostream>
#include<string>
using namespace std;
int main(){
    int n; 
    cin >> n;
    string str;
    cin >> str;
    int count = 0;
    for(int i = 0;i < n - 1 ;i ++){
        if(str[i] =='V' && str[i + 1] == 'K') {
            count++;
        }
        int n =0;
    if(str[i] =='V' && str[i + 1] != 'K' && !n){
        n++;
        count++;
    }
    }
    cout << count;
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

// 统计字符串里有多少个 VK
int countVK(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'V' && s[i+1] == 'K') {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    string str;
    cin >> n >> str;
    
    int ans = countVK(str); // 先算不改的情况
    
    // 尝试修改每一个位置（最多改1个）
    for (int i = 0; i < n; i++) {
        char original = str[i]; // 保存原来的字符
        
        // 试改成 'V'
        str[i] = 'V';
        ans = max(ans, countVK(str));
        
        // 试改成 'K'
        str[i] = 'K';
        ans = max(ans, countVK(str));
        
        str[i] = original; // 恢复
    }
    
    cout << ans << endl;
    return 0;
}