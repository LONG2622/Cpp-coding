#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[]="ababa";
    int n =sizeof(a)/sizeof(a[0])-1;
    int flag = 1;
    for(int i=0;i<n/2;i++){
        if(a[i]!=a[n-i-1]) 
          {flag = 0;
        break;}
    }
    if (flag ==1) {cout<<"回文"<<endl;}
    else {cout<<"error";}
    return 0;
}
