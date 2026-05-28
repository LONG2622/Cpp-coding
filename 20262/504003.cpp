#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n] = {0};
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a + 0, a + n );
    int cnt = 0;
    for (int k = 0; k < n; k++) {
        int i = 0, j = n - 1;
        while (i < j) {
            if (i == k) { i++; continue; }
            if (j == k) { j--; continue; }
            int sum = a[i] + a[j];
            if (sum == a[k]) {
                cnt++;
                i++;
                j--;
            } else if (sum < a[k]) {
                i++;
            } else {
                j--;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}