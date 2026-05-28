#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,m;
    int num =0;
    int a[n]={};
    for(int i=0;i<n;i++){
        m=a[i];
        for(int j=0;j<n;j++){
           if(a[j]==m)
           num++;
        }
    }
}