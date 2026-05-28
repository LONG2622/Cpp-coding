#include <iostream>
using namespace std;

int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int sumFromOneToN(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int m, n;
    cout << "请输入两个正整数m和n（m>n）：";
    cin >> m >> n;

    int mFact = factorial(m);
    int nFact = factorial(n);
    int mnFact = factorial(m - n);
    int s1 = mFact / (nFact * mnFact);

    int sumM = sumFromOneToN(m);
    int sumN = sumFromOneToN(n);
    int s2 = sumM - sumN;

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    return 0;
}