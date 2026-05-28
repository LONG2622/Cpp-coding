#include <iostream>
using namespace std;


int splitArray(int arr[], int n, int r, int* &result) {
    int less[100], greaterEq[100];  
    int lCount = 0, geCount = 0;   
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < r) {
            less[lCount++] = arr[i];
        } else {
            greaterEq[geCount++] = arr[i];
        }
    }
    
    int resLen = lCount + 1 + geCount;
    result = new int[resLen];
 
    for (int i = 0; i < lCount; i++) {
        result[i] = less[i];
    }
    
    result[lCount] = r;
   
    for (int i = 0; i < geCount; i++) {
        result[lCount + 1 + i] = greaterEq[i];
    }
    
    return resLen;
}

）
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int arr1[] = {4,7,1,20};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int r1 = 9;
    int* res1 = nullptr;
    int resLen1 = splitArray(arr1, n1, r1, res1);
    printArray(res1, resLen1);  
    delete[] res1;
    
    int arr2[] = {3,5,2};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int r2 = 7;
    int* res2 = nullptr;
    int resLen2 = splitArray(arr2, n2, r2, res2);
    printArray(res2, resLen2);  
    delete[] res2;
    
    int arr3[] = {2,14,10,1,11,12,3,4};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    int r3 = 7;
    int* res3 = nullptr;
    int resLen3 = splitArray(arr3, n3, r3, res3);
    printArray(res3, resLen3); 
    delete[] res3;
    
   
    int arr4[] = {3,5,7,1,11,13,17,19};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    int r4 = 11;
    int* res4 = nullptr;
    int resLen4 = splitArray(arr4, n4, r4, res4);
    printArray(res4, resLen4);  
    delete[] res4;
    
    return 0;
}