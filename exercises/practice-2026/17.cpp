#include<bits/stdc++.h>
using namespace std;
int twopower(int n){
    if(n == 0) return 1;
    return 2 * twopower(n-1);
}
int main(){
    vector<int> a;
    int sum;
    while(cin >> a){
        sum += a.back();
    }
    cout << sum * twopower(a.size() - 1)<< endl;
    return 0;
}