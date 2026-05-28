#include <iostream>
#include <string>
using namespace std;
bool check(string s) {
    int len = s.size();
    if (len < 6 || len > 12) return false;
    bool has_low = 0;  // 小写
    bool has_up = 0;   // 大写
    bool has_digit = 0; // 数字
    bool has_spe = 0;  // 特殊符号 !@#$
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (!(
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') ||
            c == '!' || c == '@' || c == '#' || c == '$'
        )) {
            return false;
        }
        if (c >= 'a' && c <= 'z') has_low = 1;
        if (c >= 'A' && c <= 'Z') has_up = 1;
        if (c >= '0' && c <= '9') has_digit = 1;
        if (c == '!' || c == '@' || c == '#' || c == '$') has_spe = 1;
    }
    if (!has_spe) return false;
    int cnt = 0;
    if (has_low || has_up) cnt++; // 算字母类
    if (has_digit) cnt++;         // 算数字类
    return cnt >= 2;
}
int main() {
    string str;
    cin >> str;
    string pwd; // 临时存当前密码
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ',') {
            if (check(pwd)) {
                cout << pwd << endl;
            }
            pwd = ""; // 清空
        } else {
            pwd += str[i];
        }
    }
    if (check(pwd)) {
        cout << pwd << endl;
    }
    return 0;
}