#include<iostream>
using namespace std;
int main(){
    int l , n , m;
    cin >> l >> n >> m ;
    int a[n]={0};
    for(int i = 0 ; i < n ;i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; i < n ;j++){
            if(a[i] < a[j]){
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    int Max = 0;
    for(int i = 0 ;i < n ;i++ ){
        for(int j = 1 ; i < n ;j++){
            int Min =n;
            a[i] = 0;
           	a[j] = 0;
            for(int i= 0 ; i < n; i++){
               if(!a[i]){
                   a[i] = a[i + 1];
                   a[i + 1] = 0;
               }   
                }
            for(int i = 1 ; i < n - 2;i ++){
                if(a[i] - a[i - 1] < Min){
                    Min = a[i] - a[i - 1];
                }
            }
            if (Min > Max){
                Max = Min;
            }
            }
        }
    
cout << Max;
return 0;
}