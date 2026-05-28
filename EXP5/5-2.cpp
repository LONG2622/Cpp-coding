#include <iostream>
#include <cstring>
using namespace std;

// 统计数字字符占比
double digitPercentage(char str[]) {
    int total = strlen(str);
    int digitCount = 0;
    for (int i = 0; i < total; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            digitCount++;
        }
    }
    return total == 0 ? 0 : (digitCount * 100.0) / total;
}

int main() {
    char inputStr[100];
    cout << "请输入一个字符串：";
    cin.getline(inputStr, 100);

    double percentage = digitPercentage(inputStr);
    cout << "数字字符占比：" << percentage << "%" << endl;
    return 0;
}