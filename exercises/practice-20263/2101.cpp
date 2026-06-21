#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 50010;
const int LOG = 20;
int a[MAXN];
int fmin[LOG][MAXN];
int fmax[LOG][MAXN];
int lg[MAXN];  // 自己的log表，无歧义
void init_log() {
    lg[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}
void init(int n) {
    for (int i = 1; i <= n; i++) {
        fmin[0][i] = a[i];
        fmax[0][i] = a[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            fmin[j][i] = min(fmin[j-1][i], fmin[j-1][i + (1 << (j-1))]);
            fmax[j][i] = max(fmax[j-1][i], fmax[j-1][i + (1 << (j-1))]);
        }
    }
}
int queryMin(int l, int r) {
    int k = lg[r - l + 1];
    return min(fmin[k][l], fmin[k][r - (1 << k) + 1]);
}
int queryMax(int l, int r) {
    int k = lg[r - l + 1];
    return max(fmax[k][l], fmax[k][r - (1 << k) + 1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init_log();  // 关键！
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init(n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << queryMax(l, r) - queryMin(l, r) << '\n';
    }
    return 0;
}