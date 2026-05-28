#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m ;
    cin >> n >> m ;
    int arr[n][m + 1] = {0};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }
    double mvp = 0.0;
    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        int max = 0;
        int min = 11;
        for(int j = 0 ; j < m ; j++){
                sum += arr[i][j];
                if(arr[i][j] > max){
                    max = arr[i ][j];
                }
                if(arr[i][j] < min){
                    min = arr[i][j];
                }
            }
            sum = sum - max - min;
            arr[i][m] = (double)sum/(m - 2);
            if(arr[i][m] > mvp){
                mvp = arr[i][m];
            }

        }
        cout << fixed << setprecision(2) << mvp << endl;
        return 0;
    }