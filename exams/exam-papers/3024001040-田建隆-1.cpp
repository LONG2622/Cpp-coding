#include <iostream>
#include <cstring>
using namespace std;
int getDigits(int num, int digits[]) {
    if (num == 0) {
        digits[0] = 0;
        return 1;
    }
    int len = 0;
    while (num > 0) {
        digits[len++] = num % 10;
        num /= 10;
    }
    // 反转数组，让digits[0]是最高位（位置0）
    for (int i = 0; i < len / 2; i++) {
        int temp = digits[i];
        digits[i] = digits[len - 1 - i];
        digits[len - 1 - i] = temp;
    }
    return len;
}
int main() {
    cout << "所有奇妙数：" << endl;
    int digits[10]; 
    int count[10];     
    for (int num = 0; num <=999999999; num++) {
        memset(count, 0, sizeof(count));
        // 提取数字的每一位，得到位数len
        int len = getDigits(num, digits);
        for (int i = 0; i < len; i++) {
            count[digits[i]]++;
        }
        int isWon = 1;  
        for (int i = 0; i < len; i++) {
            if (digits[i] != count[i]) {
                isWon = 0;
                break;
            }
        }
        if (isWon == 1) {
            cout << num << endl;
        }
    }
    return 0;
}