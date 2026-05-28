//队列和栈是两种重要的数据结构，它们具有push k和pop操作。
//push k是将数字k加入到队列或栈中，pop则是从队列和栈取一个数出来。
//队列和栈的区别在于取数的位置是不同的。
//队列是先进先出的：把队列看成横向的一个通道，则push k是将k放到队列的最右边，而pop则是从队列的最左边取出一个数。
//栈是后进先出的：把栈也看成横向的一个通道，则push k是将k放到栈的最右边，而pop也是从栈的最右边取出一个数。
//假设队列和栈当前从左至右都含有1和2两个数，则执行push 5和pop操作示例图如下：
//push 5 pop
//队列 1 2 -------> 1 2 5 ------> 2 5
//push 5 pop
//栈 1 2 -------> 1 2 5 ------> 1 2
//现在，假设队列和栈都是空的。给定一系列push k和pop操作之后，
//输出队列和栈中存的数字。若队列或栈已经空了，仍然接收到pop操作，则输出error。
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        queue<int> q;
        stack<int> st;
        bool q_err = false;
        bool st_err = false;
        for (int i = 0; i < n; i++) {
            string op;
            cin >> op;
            if (op == "push") {
                int k;
                cin >> k;
                q.push(k);
                st.push(k);
            } 
            else if (op == "pop") {
                if (q.empty()) q_err = true;
                else q.pop();
                if (st.empty()) st_err = true;
                else st.pop();
            }
        }
        // 输出队列
        if (q_err) {
            cout << "error" << endl;
        }
        else {
            vector<int> tmp;
            while (!q.empty()) {
                tmp.push_back(q.front());
                q.pop();
            }
            for (int i = 0; i < tmp.size(); i++) {
                if (i > 0) cout << " ";
                cout << tmp[i];
            }
            cout << endl;
        }
        // 输出栈
        if (st_err) {
            cout << "error" << endl;
        } 
        else {
            vector<int> tmp;
            while (!st.empty()) {
                tmp.push_back(st.top());
                st.pop();
            }
            for(int i = tmp.size() - 1; i >= 0 ; i --){
                if (i < tmp.size() - 1) cout << " ";
                cout << tmp[i];
            }
            cout << endl;
        }
    }
    return 0;
}