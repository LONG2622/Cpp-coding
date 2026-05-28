#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[]="abc";
    int n =sizeof(a)/sizeof(a[0]);
    for(int i=n-2;i>=0;i--){
        cout <<a[i]<<"   ";
    }
    return 0;
}