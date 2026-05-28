#include<iostream>
#include<algorithm>
using namespace std;

struct Game {
    int t, r;
} g[505];

int n;
int fa[505]; // 并查集，表示该时间段最近可用的空位

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

bool cmp(Game a, Game b) {
    return a.r > b.r; // 奖励高的优先
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> g[i].t;
    for (int i = 1; i <= n; i++) cin >> g[i].r;

    // 按奖励降序排序
    sort(g + 1, g + n + 1, cmp);

    // 初始化并查集：第 i 个时间段初始指向自己
    for (int i = 1; i <= n; i++) fa[i] = i;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int deadline = g[i].t;
        // 从 deadline 往前找第一个空闲位置
        int pos = find(deadline);
        if (pos > 0) {
            ans += g[i].r;
            fa[pos] = find(pos - 1); // 该时间段被占用
        }
    }
    cout << ans;
    return 0;
}