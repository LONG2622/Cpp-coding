#include <iostream>
using namespace std;
int main(){
    int a,b,c,n1,n2,n3;
    long long x=1,y=1,z=1;
    cout<<"请输入三个正整数：a,b,c"<<endl;
    cin>>a>>b>>c;
    for(n1=1;n1<=a;n1++){
        x*=n1;
    }
    for(n2=1;n2<=b;n2++){
        y*=n2;
    }
    for(n3=1;n3<=c;n3++){
        z*=n3;
    }
    cout<<"a!+b!+c!="<<x+y+z<<endl;
    return 0;
}
