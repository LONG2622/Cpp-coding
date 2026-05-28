#include <iostream>
#include <string>
using namespace std;
int main(){
    char a[]={"  a  d  "};
    cin.getline(a, sizeof(a)/sizeof(a[0]));
    for(long long unsigned int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        if(a[i]!=' '){
            cout<<a[i];
        }
    }
}