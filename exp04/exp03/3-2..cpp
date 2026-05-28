#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    long long fib[40];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 40; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout<<"斐波那契数列前40项为："<<endl;
    for (int i = 0; i < 40; i++) {
         cout << left << setw(12) << fib[i];
    
        if((i+1)%8==0){

    cout<<endl;
    }
}

    return 0;
}
