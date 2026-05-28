#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x, int y) {
    return abs(x) > abs(y);
}
int main(){
    int n ;
    while(cin >> n ){
        if(n == 0) return 0; 
        int a[105];           
        for(int i = 0 ; i < n ; i ++){
            cin >> a[i];
        }
        sort(a, a + n, cmp);
        for(int i = 0 ; i < n ; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}