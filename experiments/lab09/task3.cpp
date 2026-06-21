#include <iostream>
#include <string>
using namespace std;
int main(){
    char a[]={"xxxxy"};
    char b[]={"xx"};
    int j = 0;
    for(long long unsigned int i=0;i<sizeof(a)/sizeof(a[0])-1;i++){
        if(a[i]==b[0]){
            if(a[i+1]==b[1]){
                j++;
            }
            i++;
        }
        }
        cout<<j<<endl;
        return 0;
    }