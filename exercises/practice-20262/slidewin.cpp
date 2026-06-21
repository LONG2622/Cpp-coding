#include<iostream>
using namespace std;
int  val[1000005] , Min[1000005] , Max[1000005];
int main(){
    int n , m ;
     cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> val[i];
    }
    for(int i = 0 ; i < n - m + 1;i++){
        int ma = -1e9 ;
        int mi = 1e9;
        for(int j = i ; j < i + m; j++){
        if(val[j] > ma){
            ma = val[j];
        }
        if(val[j] < mi){
            mi = val[j];
        }
    }
        Max[i] = ma;
        Min[i] = mi;
    }
    for(int i = 0 ; i < n - m + 1; i++){
        cout << Max[i] << " ";
    }
    cout << endl;
    for(int i = 0 ; i < n - m + 1; i++){
        cout << Min[i] << " ";
    }
    return 0;
}