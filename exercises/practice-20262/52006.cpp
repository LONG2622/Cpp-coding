#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        int K;
        cin >> str >> K;
        int cnt[26] = {0};
        long long ans = 0;
        int left = 0, over = 0; 
        for (int right = 0; right < str.size(); right++) {
            int c = str[right] - 'a';
            if (cnt[c] == K) {
                over++;
            } 
            cnt[c]++;
            while (over > 0) {
                int d = str[left] - 'a';
                cnt[d]--;
                if (cnt[d] == K) over--; 
                left++;
            }
            ans += right - left + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}