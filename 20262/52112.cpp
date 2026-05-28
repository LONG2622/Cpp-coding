//题目描述
//有一个有趣的游戏，从一个数 K 开始，然后有三种操作。
//1. 当前数乘以2
//2. 如果当前数是偶数，可以除以2
//3. 当前数加1
//我们的目标是通过最少的操作次数得到数 P。 数据范围为 0 < P, K  < 100000, 并且在操作过程中当前数永远不会大于或等于100000。
//第一行是一个数T, 表示输入数据的组数。然后输入T组数据。
//每组数据包含两个整数 K and P ，分别表示开始数和目标数。
//输出
//输出最少的操作次数，如果不可能由K经过一些操作得到 P ，输出-1。
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int MAX = 100000;
int dist[MAX];
int bfs(int k,int p ){
    if(k == p){
        return 0;
    }
    memset(dist , -1 , sizeof(dist));
    queue<int>q;;
    q.push(k);
    dist[k] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int nx = x * 2;
        if ( nx < MAX && dist[nx] == -1){
            dist[nx] = dist[x] + 1;
            if(nx == p){
                return dist[nx];
            }
                q.push(nx);  
        }
        if(x% 2 ==0){
            nx = x / 2;
            if(nx >= 1 && dist[nx] == -1){
                dist[nx] = dist[x] + 1;
                if(nx == p){
                    return dist[nx];
                }
                q.push(nx);
            } 
        }
         nx = x + 1;
        if (nx < MAX && dist[nx] == -1) {
            dist[nx] = dist[x] + 1;
            if (nx == p) {
                return dist[nx];
            }
            q.push(nx);
        }
    }
    return -1;
}
int main(){
    int T ;
    cin >> T;
    while(T --){
        int K, P;
        cin >> K >>P;
        cout << bfs ( K , P) << endl;
    }
    return 0;
}