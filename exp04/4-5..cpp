#include <iostream>
using namespace std;

int main() {
    int arr[5][3];
    int rowSum[5];
    cout << "请输入5行3列的数组元素（每行输入3个数，空格分隔）：" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "第" << i + 1 << "行：";
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        rowSum[i] = 0;  
        for (int j = 0; j < 3; j++) {
            rowSum[i] += arr[i][j];  
           }
    }
    cout << "\n各行的和为：";
    for (int i = 0; i < 5; i++) {
        cout << rowSum[i] << " ";
    }
    cout << endl;
        for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4 - i; j++) { 
            if (rowSum[j] > rowSum[j + 1]) {
                int temp = rowSum[j];
                rowSum[j] = rowSum[j + 1];
                rowSum[j + 1] = temp;
            }
        }
    }
    cout << "排序后的和（由小到大）：";
    for (int i = 0; i < 5; i++) {
        cout << rowSum[i] << " ";
    }
    cout << endl;    
    return 0;
}
