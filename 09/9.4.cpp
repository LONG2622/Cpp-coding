#include <iostream>
#include <string>
using namespace std;
int main(){
    char a[]={"abcdbce"};
    char b[]={"bc"};
    char c[]={"12"};
    for(long long unsigned int i=0;i<sizeof(a)/sizeof(a[0])-1;i++){
        if(a[i]==b[0]){
            a[i]=c[0];
            if(a[i+1]==b[1]){
                a[i+1]=c[1];
            }
            i++;
        }
    }
    for(long long unsigned int i=0;i<sizeof(a)/sizeof(a[0])-1;i++){
        cout<<a[i];
    }
}