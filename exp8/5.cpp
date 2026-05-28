#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;  
char arr[MAX];          
char path[MAX];     
int used[MAX];       // 标记字符是否已使用
int len;                  // 输入字符串的实际长

void bubbleSort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {

                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void back(int depth) {
    if (depth == len) {
        path[depth] = '\0';  // 手动添加字符串结束符
        cout << path << " ";
        return;
    }

    // 遍历所有字符
    for (int i = 0; i < len; i++) {
        if (used[i]) continue;
    
        if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue;    
        used[i] = true;
        path[depth] = arr[i];

        back(depth + 1);

        used[i] = false;
        path[depth] = '\0';  // 可选，仅为路径清晰，不影响结果
    }
}

int main() {
    cout << "input string:";
    cin >> arr;

    len = 0;
    while (arr[len] != '\0') {
        len++;
    }
    
    bubbleSort(arr, len);
    for (int i = 0; i < len; i++) {
        used[i] = false;
    }
    cout << "所有排列：";
    back(0);
    cout << endl;
    return 0;
}