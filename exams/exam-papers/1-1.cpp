#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 10

// 验证n位数字数组是否为奇妙数（arr[0]是最高位，返回1=是，0=否）
int isWonderful(int arr[], int n) {
    int count[10] = {0};  // 统计0~9在数组中的出现次数
    
    // 第一步：统计数组中每个数字的出现次数
    for (int i = 0; i < n; i++) {
        // 数字不能大于位数n（如3位奇妙数，每个位置数字最大为3，否则计数超范围）
        if (arr[i] >= 10) return 0;
        count[arr[i]]++;
    }
    
    // 第二步：验证每个位置i的数字 == 数字i的出现次数
    for (int i = 0; i < n; i++) {
        if (arr[i] != count[i]) {
            return 0;
        }
    }
    
    return 1;
}

// 递归生成n位数字数组（arr：存储当前数字，pos：当前填充位置，n：总位数）
void generateNumber(int arr[], int pos, int n) {
    // 填充完n位，验证是否为奇妙数
    if (pos == n) {
        if (isWonderful(arr, n) == 1) {
            // 输出数组（即奇妙数）
            for (int i = 0; i < n; i++) {
                cout << arr[i];
            }
            cout << endl;
        }
        return;
    }
    
    // 填充当前位置：数字范围0~n（位数为n时，每个位置数字最大为n，否则计数超总位数）
    for (int num = 0; num <= n; num++) {
        arr[pos] = num;          // 当前位置填充数字num
        generateNumber(arr, pos + 1, n);  // 递归填充下一位
    }
}

int main() {
    cout << "所有奇妙数：" << endl;
    int arr[MAX_LEN];  // 存储奇妙数的数组（每个元素对应一位）
    
    // 枚举1~10位数字（覆盖所有可能的奇妙数）
    for (int n = 1; n <= MAX_LEN; n++) {
        memset(arr, 0, sizeof(arr));  // 初始化数组
        generateNumber(arr, 0, n);    // 生成并验证n位数字
    }
    
    return 0;
}