#include<iostream>
using namespace std;
struct People{
    string name;
    int year;
    int month;
    int day;
};
int main(){
    int n ;
    cin >> n;
    People p[n];
    for(int i = 0 ; i < n; i++){
        cin >> p[i].name >> p[i].year >> p[i].month >> p[i].day;
    }
    for(int i = 0 ; i < n; i++){
        int max = 0;
        for(int j = i + 1; j < n; j++){
            if(p[i].year < p[j].year || (p[i].year == p[j].year && p[i].month < p[j].month) || (p[i].year == p[j].year && p[i].month == p[j].month && p[i].day < p[j].day)){
                if(max < 1){
                    cout << p[i].name << endl;
                    max = 1;
                }
            }
            else{
                if(max < 1){
                    cout << p[j].name << endl;
                    max = 1;
                }
            }
        }
        
    }
}