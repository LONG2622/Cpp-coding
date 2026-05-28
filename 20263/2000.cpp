#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n ;
     cin >> n ;
    while(n --){
        int m ;
         cin >> m;
         int sum = 0;
        while(m){
        sum += (m%10);
        m /= 10;
        }
        if(sum % 7 == 0 ){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}