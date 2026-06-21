#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main(){
    int m ;
    cin >> m;
    while(m --){
        int n ;
        cin >> n;
        queue<int> q;
        stack<int>s;
        bool q_err = false;
        bool s_err = false;
        for(int i = 0 ; i < n ; i ++){
            string str;
            cin >> str;
            if(str == "push"){
                int k ; 
                cin >> k ;
                q.push(k);
                s.push(k);
            }
            else if(str == "pop"){
                if(q.empty()){
                    q_err = true;
                }
                else{
                    q.pop();
                }
                if(s.empty()){
                    s_err = true;
                }
                else{
                    s.pop();
                }
            }
            if(q_err){
                cout << "error" << endl;
            }
            else{
                vector<int> tmp;
                while(!q.empty()){
                    tmp.push_back(q.front());
                    q.pop();
                }
                for(int i =0 ; i < tmp.size(); i ++){
                    if(i){
                        cout << " ";
                    }
                    cout << tmp[i];
                }
                cout << endl;
            }
            if(s_err){
                cout << "error" << endl;
            }
            else{
                vector<int> tmp;
                while(!s.empty()){
                    tmp.push_back(s.top());
                    s.pop();
                }
                reverse(tmp.begin(), tmp.end());
                for(int i = 0 ; i< tmp.size() ; i ++){
                    if(i){
                        cout << " ";
                    }
                    cout << tmp[i];
                }
                cout << endl;
            }
        }
    }
    return 0;
}