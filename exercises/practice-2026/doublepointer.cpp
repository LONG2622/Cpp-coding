#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[10] = {1,0,3,0,5,0,0,8,9,0};
    int left = 0;
    for(int right = 0 ; right < 10; right++){
        if(a[right]){
            swap(a[left],a[right]);
            left++;
        }
    }
    for(int i = 0 ; i < 10; i++){
        cout << a[i] << " ";
    }
    return 0;
}