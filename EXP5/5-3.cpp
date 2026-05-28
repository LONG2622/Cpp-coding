#include <iostream>
using namespace std;

// 求最大公约数（欧几里得算法）
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 求最小公倍数（利用最大公约数推导：lcm(a,b) = a*b / gcd(a,b)）
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int num1, num2;
    cout << "请输入两个整数：";
    cin >> num1 >> num2;

    int greatestCD = gcd(num1, num2);
    int leastCM = lcm(num1, num2);

    cout << "最大公约数：" << greatestCD << endl;
    cout << "最小公倍数：" << leastCM << endl;
    return 0;
}