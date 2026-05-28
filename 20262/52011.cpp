//给定序列A={A1​,A2​,...,An​}, 要求改变序列A中的某些元素，
//形成一个严格单调的序列B（严格单调的定义为：B_i &lt; B_{i+1}, 1 \leq i &lt; N）。
//我们定义从序列A到序列B变换的代价为cost(A,B)=max(∣Ai​−Bi​∣)(1≤i≤N)。
//请求出满足条件的最小代价。
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int Max = 100005;
long long a[Max];
int n;

bool check(long long maxd) {
    long long last = -1e18; // 上一个数的最小可能值
    for (int i = 1; i <= n; i++) {
        long long low = a[i] - maxd;
        long long high = a[i] + maxd;
        
        long long cur = max(low, last + 1); // 必须大于上一个数
        if (cur > high) return false;
        
        last = cur; // 更新为当前选的值
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long l = 0, r = 1e9, ans = r;
        
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}