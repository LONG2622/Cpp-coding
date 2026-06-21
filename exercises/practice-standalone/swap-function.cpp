#include <iostream>
using namespace std;
int main()
{
    int a(16),b(18);
    swap(a,b);
    cout <<a<<b<<endl;
    return 0;
}
    int swap(int x,int y)
{
    int temp;
    temp = x;
    x= y;
    y = temp;
    cout<<"function output:x="<< x << "y="<<y<<endl;
return 0;
}