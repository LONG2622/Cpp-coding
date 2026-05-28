#include <iostream>
using namespace std;
int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    int sum =0;
    for(int i=0;i<10;i++){
        sum+=arr[i];
    }   
    int average = sum / 10;
    cout<<average<<endl;
    int j;
    int m,n = 0;
    for(j=0;j<10;j++){
    if (arr[j]<60) {
        m++;
    }
    if (arr[j]>=average) {
        n++;
    }
    }
        cout << m << " " << n << endl;
    return 0;
}