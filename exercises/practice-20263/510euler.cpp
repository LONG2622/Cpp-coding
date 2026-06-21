#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 3000005;
long long sum[MAX];   // 前缀和数组
int phi[MAX];         // 欧拉函数表
bool vis[MAX];
int prime[MAX], cnt;
// 线性筛求欧拉函数 O(n)
void euler(int n) {
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }

    // 前缀和
    sum[0] = sum[1] = 0;
    for (int i = 2; i <= n; ++i) {
        sum[i] = sum[i - 1] + phi[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 预处理 3e6 以内所有欧拉函数
    euler(MAX - 1);
    int a, b;
    while (cin >> a >> b) {
        cout << sum[b] - sum[a - 1] << '\n';
    }
    return 0;
}