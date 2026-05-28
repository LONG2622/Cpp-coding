#include <iostream>
#include <string>
using namespace std;
int main(){
    char a[] = {"otto"};
    char b[] = {"tato"};
    if(sizeof(a)/sizeof(a[0]) != sizeof(b)/sizeof(b[0])){
        cout<<"false"<<endl;
        return 0;
    }
    int count[256] = {0};
 for(long long unsigned int i = 0; i < sizeof(a)/sizeof(a[0]) - 1; i++){
        count[(unsigned char)a[i]]++;
    }
    for(long long unsigned int i = 0; i < sizeof(b)/sizeof(b[0]) - 1; i++){
        count[(unsigned char)b[i]]--;
        if(count[(unsigned char)b[i]] < 0){
            cout << "False" << endl;
            return 0;
        }
    }
    for(int i = 0; i < 256; i++){
        if(count[i] != 0){
            cout << "False" << endl;
            return 0;
        }
    }
    cout << "True" << endl;
    return 0;
}