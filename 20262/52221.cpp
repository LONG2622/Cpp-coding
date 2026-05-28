#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t ;
     cin >> t;
     while(t -- ){
        int a[5];
        int sum =0 ;
        for(int i =0 ; i < 5 ; i ++){
            cin >> a[i];
            sum += a[i];
        }
        int ma = -1;
        for(int i = 0 ; i < 5 ; i ++){
            for(int j = 0 ; j  < 5 ; j ++){
                for(int  k = 0 ; k < 5 ; k ++){
                    int sum1 = a[i] + a[j] + a[k];
                    if(sum1 %10 == 0){
                        int flag = (sum  -sum1) % 10;
                        if(!flag) flag = 10;
                        ma = max(ma , flag);
                    }
                }
            }
        }
        cout << ma << endl; 
     }
     return 0;
}