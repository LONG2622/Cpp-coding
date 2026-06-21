#include <bits/stdc++.h>
using namespace std;
struct stu{
    string name;
    int score[3];
};
int main(){
    int n ;
    cin >> n;
    stu s[1001];
    string mvp;
    int t =0;
    int arr[3];
    for(int i = 0; i < n ; i ++){
        int sum = 0;
        int max = 0;
        for(int j = 0 ; j < 3 ; j++){
            cin >> stu.name;
            cin >> stu.score[j];
            sum += stu.score[j];
        }
        if(sum > max){
                mvp = stu.name;
                for(int l = 0 ; l< 3; l++){
                    arr[l] = stu.score[l];
                }
            }
    }
    cout << mvp << " ";
    for(int i = 0 ; i < 3; i++){
        cout << arr[i] << " "; 
    }
    return 0;
}