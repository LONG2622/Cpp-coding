#include<iostream>
using namespace std;
int main(){
    int h , min ,h1 , min1;
    cin >> h >> min >> h1 >> min1;
    int sum = 0;
    if(min1 < min){
        min1 += 60;
        h1 -= 1;
    } 
    sum += (h1 - h) * 60 + (min1 - min) ;
    cout << sum << endl;
    return 0;
}