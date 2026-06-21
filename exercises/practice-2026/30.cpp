#include<iostream>
using namespace std;
bool isleapyear(int year){
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        return true;
    }
    return false;
}
int main(){
    int year,month;
    cin >> year >> month;
    int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2 && isleapyear(year)){
        cout << 29;
        return 0;
    }
    else{
        cout << day[month - 1];
    }
    return 0;
}