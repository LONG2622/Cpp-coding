#include<iostream>
using namespace std;
typedef long long ll;
ll a[600000], b[600000];
void merge(ll l, ll r) {
    ll mid = (l + r) / 2;
    ll i = l, j = mid + 1, tot = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            b[tot++] = a[i++];
        else
            b[tot++] = a[j++];
    }
    while (i <= mid) b[tot++] = a[i++];
    while (j <= r) b[tot++] = a[j++];
    for (ll i = l; i <= r; i++)
        a[i] = b[i];
}
void mergesort(ll l, ll r) {
    if (l < r) {
        ll mid = (l + r) / 2;
        mergesort(l, mid);
        mergesort(mid + 1, r);
        merge(l, r);
    }
}
int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    mergesort(1, n);
    for (ll i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}