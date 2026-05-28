#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll qpow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> fac;
    int tmp = m;
    for (int i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            fac.push_back(i);
            while (tmp % i == 0) tmp /= i;
        }
    }
    if (tmp > 1) fac.push_back(tmp);
    // 2. 容斥原理
    ll ans = 0;
    int sz = fac.size();
    for (int mask = 0; mask < (1 << sz); mask++) {
        int cnt = 0;
        ll d = 1;
        for (int i = 0; i < sz; i++) {
            if (mask & (1 << i)) {
                cnt++;
                d *= fac[i];
            }
        }
        ll num = m / d;
        ll p = qpow(num, n);
        if (cnt % 2 == 0) ans += p;
        else ans -= p;
    }
    cout << ans << endl;
    return 0;
}