#include <iostream>
using namespace std;

const int MAXN = 50010;

int fa[MAXN];   // 父节点
int rel[MAXN];  // 关系：0=同类，1=被吃，2=吃父
int n, k, ans;

// 找根 + 路径压缩 + 更新关系
int find(int x) {
    if (fa[x] != x) {
        int old_fa = fa[x];
        fa[x] = find(fa[x]);          // 递归找根
        rel[x] = (rel[x] + rel[old_fa]) % 3; // 更新和根的关系
    }
    return fa[x];
}

// 初始化
void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        rel[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    init();
    ans = 0;
    while (k--) {
        int d, x, y;
        cin >> d >> x >> y;
        // 假话 1：越界
        if (x > n || y > n) {
            ans++;
            continue;
        }
        // 假话 2：自己吃自己
        if (d == 2 && x == y) {
            ans++;
            continue;
        }
        int rx = find(x);
        int ry = find(y);
        // 同一个根：判断是否冲突
        if (rx == ry) {
            // d=1 要求同类 → rel[x] == rel[y]
            if (d == 1 && rel[x] != rel[y]) ans++;
            // d=2 要求 x 吃 y → rel[x] 应该是 (rel[y]+1)%3
            if (d == 2 && (rel[x] + 1) % 3 != rel[y]) ans++;
        } 
        // 不在一个集合：合并
        else {
            fa[rx] = ry;
            // 公式背下来！
            rel[rx] = (d - 1 - rel[x] + rel[y] + 3) % 3;
        }
    }
    cout << ans << endl;
    return 0;
}