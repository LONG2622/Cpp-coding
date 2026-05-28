#include<iostream>
#include<algorithm>
using namespace std;
struct Per{
    int num , point ;
};
// 排序规则：分数从高到低，分数相同则报名号从小到大
bool cmp(Per a, Per b) {
    if (a.point != b.point)
        return a.point > b.point;
    else
        return a.num < b.num;
}
int main(){
    int n , m ;
    cin >> n >> m ;
    Per per[5005]; 
    for(int i = 1 ; i <= n ; i ++){
        cin >> per[i].num >> per[i].point ;
    }
    sort(per + 1, per + n + 1, cmp);
    int pos = m * 3 / 2 ;
    int min = per[pos].point ;
    int cnt = 0;
    for (int i = 1 ; i <= n; i++) {
        if (per[i].point >= min) {
            cnt++;
        }
        else {
            break;
        }
    }
    cout << min << " " << cnt << endl;
    for(int i = 1 ; i <= cnt ; i ++){
        cout << per[i].num << " " << per[i].point << endl;
    }
    return 0 ;
}