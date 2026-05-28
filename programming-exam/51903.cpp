#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string add(string a, string b){
    string res;
    int carry = 0;
    for(int i = 0 ; i < a.size() || i < b.size() || carry ; i ++){
        int x = carry ;
        if(i < a.size()){
            x += a[a.size() - 1 - i] - '0';
        }
        if(i < b.size()){
            x += b[b.size() - 1 - i] - '0';
        }
        res += x % 10 + '0' ;
        carry = x / 10; 
    }
    reverse(res.begin() , res.end());
    return res;
}
int main(){
    int n ;
    cin >> n ;
    if(n == 1 || n == 2){
        cout << "1" << endl;
        return 0;
    }
    string s1 = "1" ,s2 = "1";
    for(int i = 3 ; i <= n ; i ++){
        string s3 = add(s1,s2);
        s1 = s2 ;
        s2 = s3 ;
    }
    cout << s2 << endl; 
}