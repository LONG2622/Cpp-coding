//直方图最大矩形面积
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        vector<ll> h(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &h[i]);
        }
        stack<int> st;
        ll ans = 0;
        for (int i = 0; i <= n; ++i) {
            ll now = (i == n) ? 0 : h[i];
            while (!st.empty() && now < h[st.top()]) {
                int top = st.top();
                st.pop();
                ll height = h[top];
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}