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