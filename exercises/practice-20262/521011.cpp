#include<iostream>
#include<deque>
using namespace std;
const int ma = 1000005;
int val[ma] , Max[ma] , Min[ma] ;
int n , m ;
int cnt1 = 0 , cnt2 = 0;
void getmax(){
    deque<int> q;
    for(int i = 0 ; i < n ; i ++){
        while(!q.empty() && val[i] >= val[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        while(!q.empty() && q.front() <= i - m){
            q.pop_front();
        }
        if(i >= m - 1){
            Max[cnt2++] = val[q.front()];
        }
    }
}
void getmin(){
    deque<int> q;
    for(int i = 0 ; i < n ; i ++){
        while(!q.empty() && val[i] <= val[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        while(!q.empty() && q.front() <= i - m){
            q.pop_front();
        }
        if(i >= m -1){
            Min[cnt1++] = val[q.front()];
        }
    }
 }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m ;
    for(int i =0 ; i < n ; i ++){
        cin >> val[i];
    }
    getmin();
    getmax();
    for(int i = 0 ; i < cnt2 ; i ++){
        cout << Min[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < cnt1 ; i ++){
        cout << Max[i] << " ";
    }
    return 0;
}