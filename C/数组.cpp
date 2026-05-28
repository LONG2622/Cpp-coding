#include <iostream>
using namespace std;
int main(){
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int (p*)[3]=a;
    cout<<p<<endl;
    return 0;
}