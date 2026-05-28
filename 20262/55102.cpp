#include<iostream>      //all by myself !!!
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
struct point{
    double x , y , z ;
};
bool cmp(point a , point b){
    if(a.z != b.z){
        return a.z > b.z ;
    }
    else{
        if(a.y != b.y){
            return a.y > b.y ;
        }
        else{
            if(a.x != b.x)
                return a.x > b.x ;
        }
    }
}
int main(){
    int n ;
    cin >> n;
    point p[50005];
    for(int i = 1 ; i <= n ; i ++){
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    sort(p + 1 , p + 1 + n , cmp);
    double sum = 0;
    for(int i = 1 ; i < n ; i++){
        sum += sqrt((p[i].x -p[i + 1].x) * (p[i].x - p[i + 1].x) +
                    (p[i].y -p[i + 1].y) * (p[i].y - p[i + 1].y) +
                    (p[i].z -p[i + 1].z) * (p[i].z - p[i + 1].z)) ;
    }
    cout << fixed << setprecision(3) << sum ;
}