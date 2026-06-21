#include <iostream>
#include <vector>
using namespace std;
void checkMagicTriangle(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> tri; 
    int isMagic = 1; 

    if (n < 3 || (n + 3) % 3 != 0) {
        isMagic = 0;
    } else {
        int k = (n + 3) / 3; // 每条边的元素个数
        int sum1 = 0, sum2 = 0, sum3 = 0;

        for (int i = 0; i < k; i++) sum1 += arr[i];
        for (int i = k - 1; i < 2 * k - 1; i++) sum2 += arr[i];
        for (int i = 2 * k - 2; i < n; i++) sum3 += arr[i];
        sum3 += arr[0];
        if (sum1 != sum2 || sum1 != sum3) {
            isMagic = 0;
        } else {
            tri.push_back({arr[0]});
            for (int i = 1; i < k - 1; i++) {
                tri.push_back({arr[i], arr[k - 1 + i]});
            }
            vector<int> lastRow;
            for (int i = 2 * k - 2; i < n; i++) lastRow.push_back(arr[i]);
            lastRow.push_back(arr[k - 1]);
            tri.push_back(lastRow);
        }
    }
    cout << "数组：";
    for (int num : arr) cout << num << " ";
    cout << endl;

    if (isMagic == 1) {
        cout << "能";
        for (auto& row : tri) {
            for (int num : row) cout << num << " ";
            cout << endl;
        }
    } else {
        cout << "不能"<<endl;
    }
}

int main() {
    vector<vector<int>> tests = {
        {1,5,3,4,2,6}, 
        {1,2,3,4,5,6},
        {2,5,9,1,6,7,3,4,8}
    };
    for (auto& arr : tests) {
        checkMagicTriangle(arr);
    }
    return 0;
}