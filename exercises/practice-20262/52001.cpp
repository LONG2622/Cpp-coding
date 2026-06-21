#include<iostream>
#include<algorithm>
using namespace std;
struct Stu{
    int chi , math ;
};
int main(){
    int n ;
    cin >> n ;
    Stu s[105];
    for(int i = 0 ; i < n ; i ++){
        cin >> s[i].chi >> s[i].math;
    }
    sort(s , s+ n , [](const Stu &a , const Stu &b){
        if(a.chi != b.chi){
            return a.chi < b.chi;
        }
        return a.math < b.math;
    });
    for(int i = 0; i < n ; i ++){
        cout << s[i].chi << " " << s[i].math << endl;
    }
    return 0;
}