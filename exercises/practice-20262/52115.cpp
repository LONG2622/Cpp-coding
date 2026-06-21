#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i = 0 ; i< n ; i ++){
        cin >> a[i];
    }
    int cur = 0;
    int best = 0;
    for(int i = 0 ; i< n ; i ++){
        cur = max(a[i] , cur + a[i]);
        best = max(best, cur);
    }
    cout << max(best , 0) << endl;
}