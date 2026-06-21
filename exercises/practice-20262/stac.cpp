#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int m;
    cin >> m;  // 测试用例组数    
    while (m--) {
        int n;
        cin >> n;  // 每组操作数       
        queue<int> q;     // 队列
        stack<int> st;    // 栈
        bool q_err = false;  // 队列是否出错
        bool st_err = false; // 栈是否出错
        
        for (int i = 0; i < n; ++i) {
            string op;
            cin >> op;
            
            if (op == "push") {
                int k;
                cin >> k;
                q.push(k);
                st.push(k);
            } else if (op == "pop") {
                // 处理队列
                if (q.empty()) q_err = true;
                else q.pop();
                
                // 处理栈
                if (st.empty()) st_err = true;
                else st.pop();
            }
        }
        if (q_err) {
            cout << "error" << endl;
        } else {
            vector<int> temp;  // 临时存队列元素，保证顺序输出
            while (!q.empty()) {
                temp.push_back(q.front());
                q.pop();
            }
            for (int i = 0; i < temp.size(); ++i) {
                if (i > 0) cout << " ";
                cout << temp[i];
            }
            cout << endl;
        }
        if (st_err) {
            cout << "error" << endl;
        } else {
            vector<int> temp;
            while (!st.empty()) {
                temp.push_back(st.top());
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            for (int i = 0; i < temp.size(); ++i) {
                if (i > 0) cout << " ";
                cout << temp[i];
            }
            cout << endl;
        }
    }
    return 0;
}