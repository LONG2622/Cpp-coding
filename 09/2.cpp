#include<iostream>
#include<cmath>
using namespace std;
class base{
    protected:
        int a,n;
    public:
    virtual void setab(int i,int j=0){
        a=i;n=j;
    }
    virtual void disp()=0;
};
class pa1:public base{
    public:
    void disp(){cout<<a*a<<endl;}};
class pa2:public base{
    public:
    void disp(){cout<<a*a*a<<endl;};
};
class pan:public base{
    public:
    void disp(){
        cout<<pow(double(a), double(n))<<endl;}
};
int main(){base *pa;pa1 obj1;pa2 obj2;pan obj3;
    pa=&obj1;pa->setab(10);pa->disp();
    pa=&obj2;pa->setab(5);pa->disp();
    pa=&obj3;pa->setab(5,4);pa->disp();
    return 0;
}