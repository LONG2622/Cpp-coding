#include <iostream>
using namespace std;
int main(){
    int arr[100];
    int n;
    cout << "input number (max 8): ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter number to delete: ";
    int del;
    cin >> del;
    int len = n;
    for(int i = 0; i < len; i++){
        if(arr[i] == del){
            for(int j = i; j < len-1; j++){
                arr[j] = arr[j + 1];
            }
            i --; 
            len --;
        }
    }
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}