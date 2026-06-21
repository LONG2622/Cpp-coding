#include<iostream>
#include<climits>
using namespace std;
const int x = 125 ;
int a[x][x] = { 0};
int dp [x][x] = {0};
int main(){
    int n ;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a[i][j];
            if(i == 0){
                dp[i][j] = a[i][j];
            }
            else{
                dp[i][j] = dp[i - 1][j] + a[i][j];
            }
        }
    }
    int max = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j ++){
            int temp = 0 ;
            for(int k = 0 ; k < n ; k++){
                if(i == 0){
                    temp += dp[j][k];
                }
                else{
                    temp += dp[j][k] - dp[i][k];
                }
                if(temp < 0){
                    temp = 0;
                }
                else if(temp > max){
                    max = temp;
                }
            }
        }        
    }
    cout << max;
    return 0;
}