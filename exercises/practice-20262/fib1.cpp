#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a ,string b){
    int carry = 0;
    string res= "";
    int i = a.size() - 1, j = b.size() - 1, c;
    while(i >= 0 || j >= 0 || carry){
        c = carry;
        if(i >= 0){
            c += a[i --] - '0';
        }
        if(j >= 0){
            c += b[j --] - '0' ;
        }
        carry = c / 10;
        res += (c % 10) + '0';
    }
    reverse(res.begin() , res.end());
    return res;
}
string fib(int n ){
    if(n == 1 || n == 2){
        return "1";
    }
    string a = "1", b = "1";
    string c;
    for(int i = 3 ; i <= n ; i ++){
        c = add(a,b);
        a=b ;
        b=c;
    }
    return b;
}
int main(){
    int  n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}