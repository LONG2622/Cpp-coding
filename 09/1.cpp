#include <iostream>
using namespace std;
class Base{
public:
    virtual void fun(int x) {
        cout << "Base class x= " << x <<endl;
    }
};
class subclass: public Base{
    public:
    virtual void fun(int x) {
        cout << "subclass x= " << x << endl;
    }
    void Test(Base* p) {    
        int a =2;
        p->fun(a);
    } 
};
    int main() {
        Base obj1;
        subclass obj2;
        obj2.Test(&obj1); 
        obj2.Test(&obj2); 
        return 0;
    }