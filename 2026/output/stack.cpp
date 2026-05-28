#include<iostream>
using namespace std;
int main(){
    int m ;
    cin >> m  ;
    while(m --){
        int n;
        cin >> n ;
        queue<int> q ;
        stack<int> s ;
        bool flag = false ;
        if(op == "push"){
            q.push(x);
            s.push(x);
        }
        else if(op == "pop"){
            if(q.empty() || s.empty()){
                flag = true ;
                break ;
            }
            int a = q.front() ;
            int b = s.top() ;
            q.pop();
            s.pop();
            if(a != b){
                flag = true ;
                break ;
            }
        }
        
    }

}