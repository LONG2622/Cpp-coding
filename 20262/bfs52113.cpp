//但seeyou的手中只有两个杯子，它们的容量分别是N 毫升和M 毫升可乐的体积为S（S<101）毫升 (正好装满一瓶) ，
//它们三个之间可以相互倒可乐 (都是没有刻度的，且 S==N+M，101＞S＞0，N＞0，M＞0) 。
//聪明的ACMER你们说他们能平分吗？如果能请输出倒可乐的最少的次数，如果不能输出"NO"。
//输入描
//三个整数 :S 可乐的体积 , N 和 M是两个杯子的容量，以"0 0 0"结束。
//输出描述
//如果能平分的话请输出最少要倒的次数，否则输出"NO"。
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct water{
    int s , n , m ;
    int count;
};
int S, N, M;
// 标记是否访问过
bool vis[105][105][105];
int bfs(){
    memset(vis , false , sizeof(vis));
    queue<water>q;
    q.push( {S ,0 , 0 , 0});
    vis[S][0][0] = true;
    int tar = S / 2;
    while(!q.empty()){
        water now = q.front();
        q.pop();
        if((now.s == tar && now.n == tar)
    || (now.s == tar && now.m == tar)
    ||(now.n == tar && now.m == tar)){
        return now.count;
    }
    if(now.s > 0 && now.n < N){
        int pour = min(now.s, N - now.n);
            water next = now;
            next.s -= pour;
            next.n += pour;
            next.count++;
            if (!vis[next.s][next.n][next.m]) {
                vis[next.s][next.n][next.m] = true;
                q.push(next);
            }
    }
    if (now.s > 0 && now.m < M) {
            int pour = min(now.s, M - now.m);
            water next = now;
            next.s -= pour;
            next.m += pour;
            next.count++;
            if (!vis[next.s][next.n][next.m]) {
                vis[next.s][next.n][next.m] = true;
                q.push(next);
            }
        }
        // 3. N杯 → 瓶子
        if (now.n > 0 && now.s < S) {
            int pour = min(now.n, S - now.s);
            water next = now;
            next.n -= pour;
            next.s += pour;
            next.count++;
            if (!vis[next.s][next.n][next.m]) {
                vis[next.s][next.n][next.m] = true;
                q.push(next);
            }
        }
        // 4. N杯 → M杯
        if (now.n > 0 && now.m < M) {
            int pour = min(now.n, M - now.m);
            water next = now;
            next.n -= pour;
            next.m += pour;
            next.count++;
            if (!vis[next.s][next.n][next.m]) {
                vis[next.s][next.n][next.m] = true;
                q.push(next);
            }
        }
        // 5. M杯 → 瓶子
        if (now.m > 0 && now.s < S) {
            int pour = min(now.m, S - now.s);
            water next = now;
            next.m -= pour;
            next.s += pour;
            next.count++;
            if (!vis[next.s][next.n][next.m]) {
                vis[next.s][next.n][next.m] = true;
                q.push(next);
            }
        }
        // 6. M杯 → N杯
        if (now.m > 0 && now.n < N) {
            int pour = min(now.m, N - now.n);
            water next = now;
            next.m -= pour;
            next.n += pour;
            next.count++;
            if (!vis[next.s][next.n][next.m]) {
                vis[next.s][next.n][next.m] = true;
                q.push(next);
            }
        }
    }
    return -1;
    }
int main(){
 while (cin >> S >> N >> M) {
        if (S == 0 && N == 0 && M == 0) break;
        if (S % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }
        int ans = bfs();
        if (ans == -1) cout << "NO" << endl;
        else cout << ans << endl;
    }
    return 0;
}