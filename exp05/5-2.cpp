#include<iostream>
using namespace std;
int plus1(int arr[], int n, int* &result) {
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        int sum = arr[i] + carry;
        arr[i] = sum % 10;
        carry = sum / 10;
        if (carry == 0) break;  
    }
    
    if (carry == 0) {
        result = new int[n];
        memcpy(result, arr, n * sizeof(int));
        return n;
    }
    // 情况2：有进位（如[9,9,9,9]→[1,0,0,0,0]）
    else {
        result = new int[n + 1];
        result[0] = 1;  // 首位为1
        for (int i = 1; i <= n; i++) {
            result[i] = arr[i - 1];
        }
        return n + 1;
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
    // 测试用例1：[1,3,2,4]
    int arr1[] = {1,3,2,4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int* res1 = nullptr;
    int resLen1 =  plus1 (arr1, n1, res1);
    printArray(res1, resLen1);  // 输出：1 3 2 5
    delete[] res1;  // 释放内存
    
    // 测试用例2：[1,4,8,9]
    int arr2[] = {1,4,8,9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int* res2 = nullptr;
    int resLen2 = plus1(arr2, n2, res2);
    printArray(res2, resLen2);  // 输出：1 4 9 0
    delete[] res2;
    
    int arr3[] = {9,9,9,9};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    int* res3 = nullptr;
    int resLen3 = plus1(arr3, n3, res3);
    printArray(res3, resLen3); 
    delete[] res3;
    
    return 0;
}