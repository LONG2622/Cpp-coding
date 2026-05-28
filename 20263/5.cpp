#include<bits/stdc++.h>
using namespace std;
int main(){
    int N , T ; 
    cin >> N >> T;
    int weight[N] ={0};
    int value[N] = {0};
    double dan [N] = {0};
    double max = 0;
    int note = 0;
    double sum = 0;
    for(int i = 0 ; i < N; i++){
        cin >> weight[i] >> value[i];
        dan[i] = (double)value[i] / weight[i];
    }
    for(int  i = 0 ; i < N; i++){
        double max = -1;
        int note = -1;
        for(int j = 0 ; j < N; j++){
            if(dan[j] > max){
                max = dan[j];
                note = j;
            }
        }
         if(T == 0) break;
        if(weight[note] <= T){
            sum += value[note];
            T -= weight[note];
        }
        else{
            sum+= T * dan[note];
            T = 0;
        }        
        dan[note] = 0;
    }
    cout << fixed << setprecision(2) << sum ;
    return 0;
}