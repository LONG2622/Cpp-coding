#include<iostream>
using namespace std;
const int MAX = 105;
char map[MAX][MAX];
int n ,m;
int dx[]= {-1,-1,-1,0,0,1,1,1};
int dy[]= {-1,0,1,-1,1,-1,0,1};
void dfs(int x,int y){
    map[x][y] = '.';
    for(int i = 0 ; i < 8 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 
            && ny < m && map[nx][ny] == 'W') {
            dfs(nx, ny);
        }
    }
}
int main(){
    cin >> n>> m;
    for(int i = 0 ; i < n ; i++){
        cin >> map[i];
    }
    int count =0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 'W') {
                count++;
                dfs(i, j);
            }
        }
    }
    cout << count ;
    return 0;
}