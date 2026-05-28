//给一个数组，表示 N 头奶牛的身高，然后有 Q 个查询。
//每个查询给出一个区间 [A, B]（从第 A 头到第 B 头），要你快速回答这个区间内最高身高和最低身高的差值。
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 50005;
const int LOG = 17;  // 2^16=65536 > 50000

int st_max[LOG][MAXN];
int st_min[LOG][MAXN];
int log2_[MAXN];

int main() {
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> st_max[0][i];
        st_min[0][i] = st_max[0][i];
    }
    
    // 预处理 log2
    log2_[1] = 0;
    for (int i = 2; i <= N; i++) {
        log2_[i] = log2_[i / 2] + 1;
    }
    
    // ST 表预处理
    for (int k = 1; k <= log2_[N]; k++) {
        int len = 1 << (k - 1);
        for (int i = 1; i + (1 << k) - 1 <= N; i++) {
            st_max[k][i] = max(st_max[k-1][i], st_max[k-1][i + len]);
            st_min[k][i] = min(st_min[k-1][i], st_min[k-1][i + len]);
        }
    }
    
    // 处理查询
    while (Q--) {
        int l, r;
        cin >> l >> r;
        int k = log2_[r - l + 1];
        int len = 1 << k;
        int mx = max(st_max[k][l], st_max[k][r - len + 1]);
        int mn = min(st_min[k][l], st_min[k][r - len + 1]);
        cout << mx - mn << "\n";
    }
    
    return 0;
}