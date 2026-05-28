#include <iostream>
using namespace std;

// 绝对值函数模板
template <typename T>
T absValue(T x) {
    return x < 0 ? -x : x;
}

int main() {
    int intNum = -10;
    float floatNum = -3.14f;
    double doubleNum = -6.28;

    cout << "整数" << intNum << "的绝对值：" << absValue(intNum) << endl;
    cout << "单浮点数" << floatNum << "的绝对值：" << absValue(floatNum) << endl;
    cout << "双浮点数" << doubleNum << "的绝对值：" << absValue(doubleNum) << endl;

    return 0;
}