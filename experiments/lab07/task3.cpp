#include <iostream>
#include <vector>
using namespace std;
int Func(const vector<int>arr)
{
    int n = arr.size();
    if(n == 1)
    return 0;
    int sum = 0;
    for(int num :arr)sum+=num;
    int Lsum = 0;
    for(int i = 0;i<n;i++){
        int Rsum =sum - Lsum -arr[i];
        if(Lsum == Rsum)return i;
        Lsum+=arr[i];
    }
    return -1;
}

int main() {
    vector<vector<int>> tests = {{3}, {2,10,2}, {1,8,5,4},{-4,1,5,2,-4,4,2}};
    for (auto& arr : tests) {
        cout << "数组：";
        for (int num : arr) cout << num << " ";
        int res = Func(arr);
        if (res != -1) cout << "\n平衡点是：" << res << "\n";
        else cout << "\n没有平衡点\n";
    }
    return 0;
}