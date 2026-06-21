#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  n , k ;
    cin >> n >> k;
    int a[n];
    for(int  i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    deque<int> mi;
    int minval[n];
    for(int i = 0 ; i < n ; i ++){
        if(!mi.empty() && mi.front() <= i - k){
            mi.pop_front();
        }
        while(!mi.empty() && a[i] <= a[mi.back()] > a[i]){
            mi.pop_back();
        }
        mi.push_back(i);
        if( i>= k - 1){
            minval[i - k + 1] = a[mi.front()];
        }
    }
    


}