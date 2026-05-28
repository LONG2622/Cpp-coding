#include<iostream>
using namespace std;
bool isleapyear(int n){
    if((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)){
        return true;
    }
    return false;
}
int main(){
    int y , d, m1 , h , h2;
    cin >> y >>  m1 >> d >> h >> h2;
    int year[13] = { 0, 31 , 28 , 31 , 
        30 , 31 ,30 , 31 ,31 ,30 ,31 , 30 ,31};
    int year1[13] = { 0, 31 , 29 , 31 , 
        30 , 31 ,30 , 31 ,31 ,30 ,31 , 30 ,31};
    d += (h + h2) / 24;
    h = (h + h2) % 24;
    int d2;
    if(isleapyear(y)){
        while(d > year1[m1]){
            d -= year1[m1];
            m1++;
        }
        if(m1 > 12){
            y += (m1 - 1) / 12;
            m1 = (m1 - 1) % 12 + 1;
        }
    }
    else{
        while(d > year[m1]){
            d -= year[m1];
            m1++;
        }
        if(m1 > 12){
            y += (m1 - 1) / 12;
            m1 = (m1 - 1) % 12 + 1;
        }
    }
    cout << y << " " << m1 << " " << d << " " << h;
} 