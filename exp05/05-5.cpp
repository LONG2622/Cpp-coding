#include<iostream>
using namespace std;

int main() {
    int arr1[] = {1,2,3,4,4,4,3,3,2,4};
    int n = sizeof(arr1)/sizeof(arr1[0]);  
    int elem[10] = {0};  
    int count[10] = {0};
    int m = 0;           
    for (int i = 0; i < n; i++) {
        int current = arr1[i];  
        int index = -1; 
        for (int j = 0; j < m; j++) {
            if (elem[j] == current) {
                count[j]++;   
                index = j;
                break;   
            }
        }

            if (index != -1) {
            elem[m] = current;
            count[m] = 1;
            m++; 
        }
    }

    int maxCount = 0;

    for (int k = 0; k < m; k++) {
        if (count[k] > maxCount) {
            maxCount = count[k];
        }
    }
    cout << "数组的众数为：";
    for (int k = 0; k < m; k++) {
        if (count[k] == maxCount) {
            cout << elem[k] << " ";
        }
    }
    cout << endl;

    return 0;
}