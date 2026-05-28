#include<iostream>
const int M = 205;
int light[M][M] = {0};
using namespace std;
int n , f , s;
void torch(int x, int y){
    int dx[] = {-2 , -1 , -1 , -1 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 2};
    int dy[] = {0 , -1 , 0 , 1 , -2 , -1 , 1 , 2 , -1 , 0 , 1 , 0};
    for(int d = 0 ; d < 12 ;d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx>= 1 && nx<= n && ny >= 1 && ny <= n){
            light[nx][ny] = 1;
        }
    }
}
void stone(int x ,int y){
    for(int i = -2 ; i <= 2 ; i++){
        for(int j = -2; j <= 2 ;j++){
            int nx = x + i;
            int ny = y + j;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n){
                light[nx][ny] = 1; 
            }
        }
    }
}
int main(){
    cin >> n >> f >> s;
    for (int i = 0; i < f; i++) {
        int x, y;
        cin >> x >> y;
        torch(x, y);
    }
    for (int i = 0; i < s; i++) {
        int x, y;
        cin >> x >> y;
        stone(x, y);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!light[i][j]) ans++;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}