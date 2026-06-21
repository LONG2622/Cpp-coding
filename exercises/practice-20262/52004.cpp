#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll; 
int main() {
    int L, N, M, cas = 1;
    while (cin >> L >> N >> M) {
        vector<ll> A(L), B(N), C(M);
        for (int i = 0; i < L; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];
        for (int i = 0; i < M; ++i) cin >> C[i];
        vector<ll> ab;
        for (ll a : A)
            for (ll b : B)
                ab.push_back(a + b);    
        // 排序 + 去重，加速二分
        sort(ab.begin(), ab.end());
        ab.erase(unique(ab.begin(), ab.end()), ab.end());
        int S; cin >> S;
        cout << "Case " << cas++ << ":\n";       
        while (S--) {
            ll X; cin >> X;
            bool ok = false;
            for (ll c : C) {
                ll target = X - c;
                if (binary_search(ab.begin(), ab.end(), target)) {
                    ok = true;
                    break;
                }
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}