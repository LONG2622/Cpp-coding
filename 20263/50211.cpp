#include<iostream>
using namespace std;
int main(){
    int a[100005];
    int n ;
    cin >> n;
    for(int i = 1 ; i < n ; i++){
        cin >> a[i];
    }
    int m ;
    cin >> m;
    while(m -- ){
        int x , y;
        int sum = 0 ;
        cin >> x >> y;
        for(int i = x ;i <= y ;i++){
            sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}