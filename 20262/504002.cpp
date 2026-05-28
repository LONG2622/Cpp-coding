#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n , m ;
    cin >> n >> m;
    char a[n][m];
    int dx[] = {0 , 0 , -1 , 1};
    int dy[] = {1 , -1 , 0 , 0};
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            cin >> a[i][j];
        }
    }
    int count = m  * n;
    int bad = 0;
    int maxc = 0;
    for(int i = 0 ;i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(a[i][j] == '.'){
                bool ok = 1;
                for(int d = 0 ; d < 4 ;d ++){
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if(x>=0 && x<n && y>=0 && y<m){
                        if(a[x][y] == '#'){
                            ok = 0;
                            break;
                        }
                    }
                }
                if(ok){
                    bad ++ ;
                }
            }
        }
    }
            maxc = bad;
    for(int i = 0; i < n ; i ++){
        for(int j = 0 ; j < m ;  j ++){
            if(a[i][j] == '#'){
                a[i][j]= '.';
                int now = 0;
                for(int x=0;x<n;x++){
                    for(int y=0;y<m;y++){
                        if(a[x][y] == '.'){
                            bool ok = 1;
                            for(int d=0;d<4;d++){
                                int nx = x + dx[d];
                                int ny = y + dy[d];
                                if(nx>=0 && nx<n && ny>=0 && ny<m){
                                    if(a[nx][ny] == '#'){
                                        ok = 0;
                                        break;
                                    }
                                }
                            }
                            if(ok) now++;
            }
        }
    }
                if(now > maxc) {
                    maxc = now;
                } 
                // 恢复回去
                a[i][j] = '#';
            }
        }
    }
 cout << maxc << endl;
    return 0;
}