#include <iostream>
using namespace std;
int main(){

int i=10;
int *p;
p=&i;
cout<<"a的地址"<<&i<<endl;
cout<<p<<endl;//利用重载的插入运算符输出表中元
return 0;
}