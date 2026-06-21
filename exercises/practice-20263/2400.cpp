#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int maze[5][5];
pair<int,int> pre[5][5];
int dx[4] = { -1 , 1 , 0 , 0};
int dy[4] = { 0 , 0 , -1 , 1};
bool isVisited[5][5];

void bfs(){
    queue<pair<int , int>> q;
    q.push({0,0});
    isVisited[0][0] = true;
while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
}
if(x == 4&& y == 4){
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
for(int i = 0 ;i < 4 ;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
        if(!isVisited[nx][ny] && maze[nx][ny] == 0){
            q.push({nx,ny});
            isVisited[nx][ny] = true;
            pre[nx][ny] = {x,y};

        }
    }
}
}
void print(int x,int y){
    if(x == 0 && y == 0){
        return;
    }
    print(pre[x][y].first,pre[x][y].second);
    cout<<"("<<x<<","<<y<<")"<<endl;
}
int main(){
    for(int i = 0 ; i < 4 ;i++){
        for(int j = 0 ; j < 4 ;j++){
            cin>>maze[i][j];
        }
    }
        memset(isVisited,false,sizeof(isVisited));
        bfs();
        print(4,4);
        return 0;
}