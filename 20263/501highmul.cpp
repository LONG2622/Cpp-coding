#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    int a[10005] , b[10005] , c[10005];
    for(int i = 0 ; i  < s.size() ; i++){
        a[i] = s[s.size() - i - 1] - '0';
    }
    for(int i = 0 ; i < t.size() ; i++){
        b[i] = t[t.size() - i - 1 ] - '0';
    }
    for(int i = 0  ; i < s.size() ; i++){
        for( int j = 0 ; j < t.size() ;j++){
                c[i + j ] += a[i] * b[j];
        }
    }
    for (int i = 0; i < s.size() + t.size(); i++) {
        if (c[i] > 9){
            c[i + 1] += c[i] / 10, c[i] %= 10;
}
}
int len = s.size() + t.size();
while (c[len] == 0 && len > 1)
  len--;
while (len > 0)
  cout << c[len], len--;
  return 0;
}