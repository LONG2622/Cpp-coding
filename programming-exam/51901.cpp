#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    while(n --){
        int a[5];
        int sum = 0 ;
        for(int i =0 ; i < 5 ; i ++){
            cin >> a[i];
            sum += a[i];
        }
        int ma = -1;
        for(int i = 0 ; i < 3 ; i ++){
            for(int j = i + 1; j < 4 ; j ++){
                for(int k = j  + 1; k < 5 ; k ++){
                    int sum1 = a[i] + a[j] + a[k];
                    if(sum1 % 10 == 0){
                    int sum2 = sum - sum1;
                    int l = sum2 % 10;
                    if(!l){
                        l = 10;
                    }
                        ma = max(ma , l);
                    }

                }
            }
        }
    cout << ma << endl ;
    }
    return 0;
}