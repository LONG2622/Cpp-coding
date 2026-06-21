#include <iostream>
#include <vector>
using namespace std;

int Func(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0; 
    int left = 0, right = n-1;
    int leftMax = height[0], rightMax = height[n-1];
    int total = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) leftMax = height[left];
            else total += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax) rightMax = height[right];
            else total += rightMax - height[right];
            right--;
        }
    }
    return total;
}

int main() {
    vector<vector<int>> tests = {{1},{0,7,10,7,3}, {7,2,9,8,5,8,9,6,3},{8,5,3},{6,2,5,9,0,4,7,9,7,1}};
    for (auto& h : tests) {
        cout << "柱子高度：";
        for (int num : h) cout << num << " ";
        cout << "\n接雨水：" << Func(h) << "\n";
    }
    return 0;
}