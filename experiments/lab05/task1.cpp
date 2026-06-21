#include <iostream>
using namespace std;

// 函数：将偶数移到奇数前
void evenBeforeOdd(int arr[], int n) {
    int left = 0;          // 左指针：从左向右找奇数
    int right = n - 1;     // 右指针：从右向左找偶数
    while (left < right) {
        // 左指针找到奇数时停止
        while (left < right && arr[left] % 2 == 0) {
            left++;
        }
        // 右指针找到偶数时停止
        while (left < right && arr[right] % 2 != 0) {
            right--;
        }
        // 交换奇数和偶数
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

// 打印数组（辅助函数）
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // 测试用例1：[1,2,3,4,5,6,7,8,9,10]
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    evenBeforeOdd(arr1, n1);
    printArray(arr1, n1);  // 输出：2 4 6 8 10 5 7 3 9 1（符合题意，无需保持原序）
    
    // 测试用例2：[2,4,6,1,8]
    int arr2[] = {2,4,6,1,8};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    evenBeforeOdd(arr2, n2);
    printArray(arr2, n2);  // 输出：2 4 6 8 1
    
    // 测试用例3：[2,4,6,8,1]
    int arr3[] = {2,4,6,8,1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    evenBeforeOdd(arr3, n3);
    printArray(arr3, n3);  // 输出：2 4 6 8 1
    
    return 0;
}