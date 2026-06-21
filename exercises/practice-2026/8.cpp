#include<bits/stdc++.h>
using namespace std;
int count(int a){
    a += 1;
    a *= 2;
    return a;
}
int main(){
    int n ; 
    cin >> n;
    int s = 1;
    for(int i = 0 ; i < n - 1; i++){
        s = count(s);
    }
    cout << s;
    return 0;
}