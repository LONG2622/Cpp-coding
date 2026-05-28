#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int w0 , w ,m ;
double cal(double u){
    double sum = 0 , v = 1;
    for(int i = 1 ; i <=  m; i ++){
        v *= ( 1 + u) ;
        sum += w / v;
    }
    return sum ;
}
int main(){
    cin >> w0 >> w >> m ;
    double l = 0  , r = 3 , mid ;
    while(r - l >= 1e-6){
        mid = (l + r) / 2;
        if(cal(mid) > w0){
            w0 = mid;
        }
        else{
            r = mid;
        }
    }
    cout << fixed << setprecision(1) << mid * 100;
    return 0;
}