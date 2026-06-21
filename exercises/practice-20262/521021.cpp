#include<iostream>
#include<string>
using namespace std;
void build(string pre, string in ,int len){
    if(!len){
        return ;
    }
    char root = pre[0];
    int pos = 0;
    while(in[pos] != root){
        pos ++;
    }
    build(pre.substr(1) , in , pos);
    build(pre.substr(pos + 1), in.substr(pos + 1 ) , len - pos + 1) ;
    cout << root;
}
int main(){
    string pre,in;
    while(cin >> pre >> in){
        build(pre, in ,pre.size()) ;
        cout << endl;
    }
    return 0;
}