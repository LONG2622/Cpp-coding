#include <iostream>
using namespace std;

class Factorial {
public:
    // 成员函数：计算n的阶乘（n≥0）
    long long calculate(int n) {
        if (n < 0) {
            cout << "错误：负数没有阶乘！" << endl;
            return -1; // 异常返回值
        }
        long long result = 1; // 用long long避免溢出（支持更大范围的阶乘）
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
};

int main() {
    Factorial fact; 
    cout << "2～9的阶乘结果如下：" << endl;
    for (int n = 2; n <= 9; n++) {
        cout << n << "! = " << fact.calculate(n) << endl;
    }
    return 0;
}