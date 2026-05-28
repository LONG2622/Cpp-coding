#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 50010;
const int LOG = 20;

int a[MAXN];
int fmin[LOG][MAXN];  // 存最小值
int fmax[LOG][MAXN];  // 存最大值

// 初始化稀疏表
void init(int n) {
    // 初始化 2^0 = 1
    for (int i = 1; i <= n; i++) {
        fmin[0][i] = a[i];
        fmax[0][i] = a[i];
    }

    // 递推构建
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            fmin[j][i] = min(fmin[j-1][i], fmin[j-1][i + (1 << (j-1))]);
            fmax[j][i] = max(fmax[j-1][i], fmax[j-1][i + (1 << (j-1))]);
        }
    }
}

// 查询最小值
int queryMin(int l, int r) {
    int k = log2(r - l + 1);
    return min(fmin[k][l], fmin[k][r - (1 << k) + 1]);
}

// 查询最大值
int queryMax(int l, int r) {
    int k = log2(r - l + 1);
    return max(fmax[k][l], fmax[k][r - (1 << k) + 1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init(n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        int mx = queryMax(l, r);
        int mn = queryMin(l, r);
        cout << mx - mn << '\n';
    }
    return 0;
}