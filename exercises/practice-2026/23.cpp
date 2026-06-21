#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int d = abs(a[i] - a[i + 1]);
        if (d >= 1 && d <= n - 1) {
            b[d]++;
        }
    }
    for (int i = 1; i <= n - 1 ; i++) {
        if (!b[i]) {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}