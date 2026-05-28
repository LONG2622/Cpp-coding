// 跳石头
//有一条河，长度为 LL，起点（位置 0）和终点（位置 L）各有一块石头。
//中间还有 NN 块石头，每块在位置 DiDi​（整数，不重复，0 < D_i < L）。
//现在有一头牛从起点跳到终点，只能踩石头（起、终也是石头）。
//如果某些石头太密集，牛可能跳得很轻松，但 Farmer John 想锻炼牛的跳跃能力。
//他可以移除 最多 M 块 中间的石头（不能移除起点和终点），目的是让牛从起点到终点过程中需要跳跃的最短距离 尽可能大。
//要问：移除最优的 M 块石头后，那个最短跳跃距离 最大能是多少？
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll ;
int main(){
    int sum ,  n , m ; 
    cin >> sum >> n >> m ;
    ll a[n];
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    sort(a , a+n);
    int ans = 0 ;
    ll l = 0 ;
    ll r = sum ;
    ll ma = 0 ;
    while(l <= r){
        ll mid = (l + r) / 2;
        int remove = 0;
        int last = 0; //上一个保留的石头的下标
        for(int i = 1 ; i < n ; i ++){
            if(a[i] - a[last] < mid){
                remove ++;
            }
            else{
                last = i ;
            }
        }
        if(sum - a[last] < mid){
            remove = m + 1; // 标记为不可行
        }
        if(remove <= m){
            ma = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ma ;
    return 0;
}