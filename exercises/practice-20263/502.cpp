#include<iostream>
#include<vector>
using namespace std;
int n ;
int ans = 0 ;
vector<bool> col;
vector<bool> dg ;//主对角线
vector<bool> udg; // 副对角线
vector<int> path;
void printChess()
{
    cout << ans << "FangAn:" << endl;
    for(int row = 0; row < n; row++)
    {
        for(int c = 0; c < n; c++)
        {
            if(c == path[row])
                cout << "Q ";   // 皇后位置
            else
                cout << ". ";   // 空位置
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
        
void print(){
    for(int i = 0 ; i < n ; i++){
            cout <<  path[i] + 1 << " ";
    }
    cout << endl;
}
void dfs(int row){
    if(row == n){
        ans++;
        if(ans <= 3){
            print();
            printChess();
        }
        return ;
    }
    for(int c = 0 ; c <  n ; c++){
        if(!col[c] && !dg[row - c + n] && !udg[row + c]){
            col[c] = true;
            dg[ row - c +n] = true;
            udg[row + c] = true;
            path[row] = c;
            dfs(row+1);
            col[c] = false;
            dg[ row - c +n] = false;
            udg[row + c] = false;
        }
    }
}
int main(){
    cin >> n;
    col.assign(n ,false);
    dg.assign(n * 2 , false);
    udg.assign(n * 2 , false);
    path.resize(n);
    ans = 0;
    dfs(0) ;
    cout << ans << endl;
    return 0;
}