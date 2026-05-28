#include <iostream>
using namespace std;
int main()
{
    int a= 10000 ;
    cout << a/3600 <<"小时" <<endl;
    cout << (a%3600) /60 <<"分钟" <<endl;
    cout << a%60 <<"秒" <<endl;   
    return 0;
 }