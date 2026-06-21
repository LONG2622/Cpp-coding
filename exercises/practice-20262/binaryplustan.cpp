#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
ll a[MAXN];
int n;

// 判断代价 maxd 是否可行
bool check(ll maxd) {
    ll last = a[0] - maxd;  // 第一个数尽量小
    for (int i = 1; i < n; i++) {
        // B[i] 必须 > last，且在 [a[i]-maxd, a[i]+maxd] 之间
        // 最小能取的值：max(a[i]-maxd, last+1)
        ll cur = max(a[i] - maxd, last + 1);
        if (cur > a[i] + maxd) return false;  // 没有合法值
        last = cur;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        ll l = 0, r = 1e9;
        ll ans = r;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << "Case #" << cas << ":" << endl;
        cout << ans << endl;
    }
    return 0;
}