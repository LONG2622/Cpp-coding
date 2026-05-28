#include <iostream>
#include <cstring>
#include <string>
using namespace std;
//保留首次出现的字符,避免录入相同字符重复统计
string deduplicate(string s) {
    string str;
    char used[256];
    memset(used, 0, sizeof(used));
    for (int i = 0; i < s.size(); i++) {
        if (used[(unsigned char)s[i]] == 0) {
            used[(unsigned char)s[i]] = 1;
            str += s[i];
        }
    }
    return str;
}
void generate(string str, int n, string cur, int start) {
    if (cur.size() == n) {
        cout << cur << " ";
        return;
    }
    for (int i = start; i < str.size(); i++) {
        // 拼接当前字符
        cur += str[i];
        generate(str, n, cur, i);
        cur = cur.substr(0, cur.size() - 1);
    }
}
int main() {
    string s;
    int n;
    cout << "请输入字符串：";
    cin >> s;
    cout << "请输入整数n:";
    cin >> n;
    string str = deduplicate(s);
    cout << "生成的字符组合：" << endl;
    generate(str, n, "", 0);
    cout << endl;
    return 0;
}