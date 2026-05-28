#include<bits/stdc++.h>
using namespace std;
struct Student{
    string name;
    int chinese;
    int math;
    int english;
};
int main(){
    int N;
    cin >> N;
    Student stu[N];
    for(int i = 0 ; i < N; i++){
        cin >> stu[i].name >> stu[i].chinese >> stu[i].math
         >> stu[i].english;
    } 
    for(int i = 0 ; i < N; i++){
        for(int j = i ; j < N; j++){
            if(stu[i].chinese <= stu[j].chinese + 5 && stu[i].chinese >= stu[j].chinese - 5){
                if(stu[i].math <= stu[j].math + 5 && stu[i].math >= stu[j].math - 5){
                    if(stu[i].english <= stu[j].english + 5 && stu[i].english >= stu[j].english - 5){
                        if(stu[i].chinese + stu[i].math + stu[i].english <= stu[j].chinese + stu[j].math + stu[j].english + 10 && stu[i].chinese + stu[i].math + stu[i].english >= stu[j].chinese + stu[j].math + stu[j].english - 10){
                            if(stu[i].name[0] < stu[j].name[0]){
                                cout << stu[i].name << " " <<stu[j].name << endl; 
                            }
                            else{
                                cout << stu[j].name << " " <<stu[i].name << endl; 
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}