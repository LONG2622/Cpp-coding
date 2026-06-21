#include<bits/stdc++.h>
using namespace std;
struct Student{
    int namecode;
    int score;
    int tuozhan;
};
int comprehension(int s,int t){
    return s * 7 + t * 3;
}
int main(){
    int  N;
    cin >> N;
    Student stu[N];
    int sum [N];
    for(int i = 0 ; i < N; i++){
        cin >> stu[i].namecode >> stu[i].score >> stu[i].tuozhan;
        sum[i] = comprehension(stu[i].score,stu[i].tuozhan);
    }
    for(int i = 0 ; i < N; i++){
        if(sum[i] >= 800 && (stu[i].score + stu[i].tuozhan) > 140){
            cout << "Excellent" << endl;
        }
        else{
            cout << "Not excellent" << endl;
        }
    }
    return 0;
}