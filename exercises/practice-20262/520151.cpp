#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<ll> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        stack<int> st;
        ll maxArea = 0;
        for (int i = 0; i <= n; i++) {
            ll curHeight = (i == n) ? 0 : h[i];
            while (!st.empty() && curHeight < h[st.top()]) {
                ll height = h[st.top()];
                st.pop();
                long long width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        cout << maxArea << endl;
    }
    return 0;
}