#include <iostream>
#include <string>
using namespace std;
int main(){
    char a[]="Abcda";
    for(long long unsigned int i=0; i<sizeof(a)/sizeof(a[0])-1; i++){
        for(long long unsigned int j=i+1; j<sizeof(a)/sizeof(a[0])-i-1; j++){
            if(a[i]==a[j]||a[i]==a[j]+32||a[i]+32==a[j]){
                cout<<"true"<<endl;
                return 0;}       
            }
        }
        cout<<"false"<<endl;
        return 0;
    }