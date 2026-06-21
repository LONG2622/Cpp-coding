#include <iostream>
using namespace std;
int main()
{
    int a ;
    cout << "输入一个三位数" <<endl;
    cin >> a ;
    cout << a%10 <<endl; 
    cout << (a%100)/10 <<endl; 
    cout << a/100 <<endl;
      
     
    return 0;
 }