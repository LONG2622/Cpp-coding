//maze一个5×5的二维数组，表示一个迷宫。数据保证有唯一解。
//左上角到右下角的最短路径，格式如样例所示。
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int maze[5][5];
// 记录每个点的前驱（从哪个点走过来的）
pair<int, int> pre[5][5];
// 四个方向：上下左右
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
// 标记是否走过
bool vis[5][5];
// BFS 找最短路径
void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;
       while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();     
        // 到达终点
        if (x == 4 && y == 4) return;
        // 四个方向走
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 合法、能走、没走过
            if (nx >=0 && nx <5 && ny >=0 && ny <5 
                && maze[nx][ny] == 0 && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pre[nx][ny] = {x, y}; // 记录前驱
                q.push({nx, ny});
            }
        }
    }
}
// 递归输出路径（从终点倒着输出）
void print(int x, int y) {
    if (x == 0 && y == 0) {
        cout << "(0, 0)" << endl;
        return;
    }
    print(pre[x][y].first, pre[x][y].second);
    cout << "(" << x << ", " << y << ")" << endl;
}
int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> maze[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    bfs();
    print(4, 4);
    return 0;
}