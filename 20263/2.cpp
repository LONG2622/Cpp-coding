#include<iostream>
#include<vector>
#include<string>
#include<stack>
typedef long long ll;
const int MOd  =10000;
using namespace std;
int main(){
    string s;
    cin >>s;
    stack<ll>st;
    ll num = 0;
    char op = '+';  //初始操作符为加号
    for(int  i = 0 ; i < s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num = num * 10 + s[i] - '0';  //将连续的数字转换成一个整数
        }
        if(s[i] == '+' || s[i] == '*' || i == s.size() - 1){  
            if(op == '+'){
                st.push(num);  //如果操作符是加号，将num压入栈中
            }else if(op == '*'){
                ll a = st.top(); st.pop();  //弹出栈顶元素a
                st.push((a * num) % MOd);  //将a和b的和模MOD后压入栈中
            }
            op = s[i];
            num = 0;  //重置num为0
            }
        }
    ll ans = 0;
    while(!st.empty()){
        ans = (ans + st.top()) % MOd;  //将栈中的元素累加到ans中，并对MOD取模
        st.pop();  //弹出栈顶元素
    }
    cout << ans << endl;
    return 0;
}