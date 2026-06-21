#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int a = 2.8 * 6 ;
    int e[] = {1,2,3,4,5,6};
    int  b = 1;
    int  *p = &e[0];
    int *q = &e[5];
    cout << q - p;
    int c = -1;
    int d = b > a > c;
    cout << d << endl;
    char s[] = {"hell"};
    cout << sizeof(s) << endl;
    cout << strlen(s) << endl;
    cout << a << endl;
    return 0;
}