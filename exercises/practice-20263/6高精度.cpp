#include<iostream>
#include<cstring>
using namespace std;
const int Max = 2000;
void add(int a[],int b[],int c[]){
    int temp[Max] = {0};
    for(int i = 0 ; i < Max ; i++){
        temp[i] = a[i] + b[i];
        temp[i+1] = temp[i] / 10;
        temp[i] %= 10;
        c[i] = temp[i];
    }
}
void print(int a[]){
    int pos = Max - 1;
    while(pos > 0 && a[pos] == 0) {
        pos --;
    }
    for(int i = pos ; i >= 0 ; i--){
        cout << a[i];
    }
    cout << endl;
}

int main(){
    int n ;
     cin >> n;
    int f1[Max] = {0};
    int f2[Max] = {0};
    int f3[Max] = {0};
    f1[0] = 1;
    f2[0] = 2;
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    for(int  i = 3; i <= n; i++){
        add(f1 , f2 , f3);
        for(int j = 0 ; j < Max; j++){
            f1[j] = f2[j];}
        for(int j = 0 ; j < Max; j++){
            f2[j] = f3[j];}
    }
    print(f2);
    return 0;
}