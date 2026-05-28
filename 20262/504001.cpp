#include<iostream>
#include<vector>
using namespace std;
struct apple{
    int x ,y;
};
vector<apple> apples;
int n , s;
int a , b;
int count = 0;
void dfs(int index, int used ,int cnt){
    if(cnt > count){
        count = cnt;
    }
    if(index >= n){
        return ;
    }
    dfs(index + 1 , used , cnt);
    apple now = apples[index];
    if(now.x <= a + b && used + now.y <= s){
        dfs(index + 1 , used + now.y , cnt + 1) ;
    } 
}
int main(){
    cin >> n >> s >> a >> b ;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        apples.push_back({x, y});
    }
    dfs(0 , 0 , 0);
    cout << count << endl;
    return 0;
}