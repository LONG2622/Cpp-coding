#include <iostream>
using namespace std;
int main(){
    int arr[]={2,4,5,8,12,14,16,18,20,30};
    int n;
    cin>>n;
    arr[10]=n;
    for(int i=0;i<11;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
