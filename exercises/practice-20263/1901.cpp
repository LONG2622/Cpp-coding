/*
#include<iostream>
using namespace std;
struct student{
    string name;
    int y,m,d;
};
int main(){
    int n ;
     cin >> n;
        student s[100];
    for(int i = 0 ; i < n ; i++){
        cin >> s[i].name >> s[i].y >> s[i].m >> s[i].d;
    }
    for(int i = 0 ; i < n ;i ++){
        for(int j = i ; j < n ; j++){
            if(s[i].y > s[j].y || (s[i].y == s[j].y && s[i].m > s[j].m) 
            || (s[i].y == s[j].y && s[i].m == s[j].m && s[i].d >= s[j].d)){
                swap(s[i],s[j]);
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << s[i].name << endl;
    }
    return 0;
}
*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct student{
    string name;
    int y,m,d;
} s[100010];
bool cmp(student a, student b){
    if(a.y != b.y) return a.y > b.y;
    if(a.m != b.m) return a.m > b.m;
    return a.d >= b.d;
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i].name >> s[i].y >> s[i].m >> s[i].d;
    }
    sort(s, s+n, cmp);
    for(int i=0; i<n; i++){
        cout << s[i].name << endl;
    }
    return 0;
}