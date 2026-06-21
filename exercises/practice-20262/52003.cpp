#include <iostream>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        long long moves = (1LL << n) - 1;
        cout << moves << endl;
    }
    return 0;
}