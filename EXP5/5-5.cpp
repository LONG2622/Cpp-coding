#include <iostream>
using namespace std;
int absValue(int x) {
    return x < 0 ? -x : x;
}
float absValue(float x) {
    return x < 0 ? -x : x;
}

double absValue(double x) {
    return x < 0 ? -x : x;
}

int main() {
    int intNum = -15;
    float floatNum = -2.71878;
    double doubleNum = -9.8;

    cout << "整数" << intNum << "的绝对值：" << absValue(intNum) << endl;
    cout << "单浮点数" << floatNum << "的绝对值：" << absValue(floatNum) << endl;
    cout << "双浮点数" << doubleNum << "的绝对值：" << absValue(doubleNum) << endl;

    return 0;
}