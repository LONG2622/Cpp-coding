 #include<iostream>
using namespace std;

int main() {
    int arr1[] = {5,5,7,9,9};
    int n = sizeof(arr1)/sizeof(arr1[0]); 
    int elem[10] = {0};   
    int count[10] = {0};  
    int m = 0;            

    for (int i = 0; i < n; i++) {
        int cur = arr1[i];
        int j; 
       
        for (j = 0; j < m; j++) {
            if (elem[j] == cur) {
                count[j]++;  
                break;      
            }
        }
        if (j == m) {
            elem[m] = cur;
            count[m] = 1;
            m++;
        }
    }
    int maxCount = 0;
    for (int k = 0; k < m; k++) {
        if (count[k] > maxCount) maxCount = count[k];
    }
    cout << "数组的众数为：";
    for (int k = 0; k < m; k++) {
        if (count[k] == maxCount) cout << elem[k] << " ";
    }
    cout << endl;
    return 0;
}