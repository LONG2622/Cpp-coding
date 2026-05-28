#include    <iostream>
using namespace std;
int minpos(int a , int n , int arr[] ){
    int min = a;
    int pos = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] < min){
            min = arr[i];
            pos = i;
        }
    }
    return pos+1;
}

int main(){
    int arr[] = {5,11,8,5,13,18};
    int a = arr[0];
    int pos = minpos(a , 6 , arr);
    cout << pos << endl;
    int arr2[] = {5,3,4,2,6,7,8,9,1,10};
    int a2 = arr2[0];
    pos = minpos(a2 , 10 , arr2);
    cout << pos << endl;  
    return 0;
}