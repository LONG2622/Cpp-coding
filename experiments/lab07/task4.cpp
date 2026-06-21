#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& coins) {
    int n = coins.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (coins[j] > coins[j + 1]) {   
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }
}

int maxChange(vector<int>& coins) {
    bubbleSort(coins); 
    int max_val = 0;
    for (int i = 0; i < coins.size(); i++) {
        if (coins[i] > max_val + 1) {
            break;
        }
        max_val += coins[i];
    }
    return max_val;
}

int main() {
     vector<vector<int>> testCases = {
        {1},                              
        {1, 1},                           
        {1, 5},                           
        {1, 2, 4},                        
        {1, 2, 3, 7},                
        {1, 1, 1, 1, 5, 10, 20, 50}       
    };
     for (auto& arr : testCases) {
        cout << "数组：";
        for (int num : arr) cout << num << " ";
        int res = maxChange(arr);
        if (res != -1) cout << "maxCharge：" << res << "\n";
        else cout << "none";
    }
    return 0;

}