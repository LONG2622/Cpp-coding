#include <iostream>
using namespace std;
int main(){
    int a,b;
    for (a=2;a<=100;a++)
    {   for(b=2;b<a;b++)
        {
            if(a%b==0)
           { break;}
        }
        if(b==a)
            {cout<<a<<"  ";}
        }    return 0;
}

