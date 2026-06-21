#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++){
        if (s[i] =='4'){
            s[i] = '8';
        }
    }
    cout << s;
    return 0;
}