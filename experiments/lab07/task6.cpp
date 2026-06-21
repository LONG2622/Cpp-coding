#include <iostream>
#include <vector>
using namespace std;

void simpleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

vector<int> distribute(vector<int> choc, int m) {
    int n = choc.size();
    simpleSort(choc); 
    int minDiff = choc[m-1] - choc[0];
    int start = 0;

    for (int i = 1; i <= n - m; i++) {
        int diff = choc[i+m-1] - choc[i];
        if(i<n){
            
        }
    }

    vector<int> res;
    for (int i = start; i < start + m; i++) res.push_back(choc[i]);
    return res;
}


int main() {
    vector<vector<int>> testCases = {
        {7,3,2,4,9,12,56},
        {3,4,1,9,56,7,9,12},
        {25,46,24,22,39,9,10,2}
    };

    for (auto& arr : testCases) {
        cout << "巧克力数组：";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
        int m = 5;
        vector<int> res = distribute(arr, m);
        cout << "分配方案：";
        for (int num : res) {
            cout << num << " ";
        }
        cout << endl << "------------------------" << endl;
    }

    return 0;
}