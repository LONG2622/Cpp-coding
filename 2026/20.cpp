#include<iostream>
using namespace std;
int two(int n){
    if(n == 0) return 1;
    return 2 * two(n - 1);
}
int a[1025][1025];
void dfs(int x,int y,int s){
    if(s == 1) return; 
    int half = s / 2;
    for(int i = x; i < x + half; i++){
        for(int j = y; j < y + half; j++){
            a[i][j] = 0;
        }
    }
    dfs(x, y + half, half);
    dfs(x + half, y, half);
    dfs(x + half, y + half, half);
}
int main(){
    int n;
    cin >> n;
    int size = two(n); 
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            a[i][j] = 1;
        }
    }
    dfs(0, 0, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }   
    return 0;
}