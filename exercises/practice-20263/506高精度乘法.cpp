#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int arr[500] = {0};
int base[500] = {0};
int temp[500] = {0};

// 高精度乘法（只保留最后500位）
void multiply(int a[], int b[]) {
    memset(temp, 0, sizeof(temp));
    
    // 只计算最后500位
    for(int i = 499; i >= 0; i--) {
        if(a[i] == 0) continue;
        int carry = 0;
        for(int j = 499; j >= 0; j--) {
            if(i + j - 499 < 0) break;  // 超出500位，忽略
            int pos = i + j - 499;
            if(pos < 0) continue;
            
            int sum = temp[pos] + a[i] * b[j] + carry;
            temp[pos] = sum % 10;
            carry = sum / 10;
        }
    }
    
    // 复制回去
    for(int i = 0; i < 500; i++) {
        a[i] = temp[i];
    }
}

void fast_pow(int p) {
    // 初始化：arr = 1, base = 2
    memset(arr, 0, sizeof(arr));
    memset(base, 0, sizeof(base));
    arr[499] = 1;      // 最低位
    base[499] = 2;     // 底数
    
    while(p > 0) {
        if(p & 1) {
            multiply(arr, base);  // arr = arr * base
        }
        multiply(base, base);     // base = base * base
        p >>= 1;
    }
    
    // 减1
    for(int i = 499; i >= 0; i--) {
        if(arr[i] > 0) {
            arr[i]--;
            break;
        } else {
            arr[i] = 9;
        }
    }
}

int main() {
    int p;
    cin >> p;
    
    // 位数
    int digits = floor(p * log10(2)) + 1;
    cout << digits << endl;
    
    // 快速幂计算
    fast_pow(p);
    
    // 输出最后500位
    for(int i = 0; i < 500; i++) {
        cout << arr[i];
        if((i + 1) % 50 == 0) {
            cout << endl;
        }
    }
    
    return 0;
}