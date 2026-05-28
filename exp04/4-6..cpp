#include <iostream>
using namespace std;
int main() {
    char str[20], s[20], temp; 
    cout << "请输入第一个字符串："<< endl;
    cin.getline(str, 20);
    cout << "请输入第二个字符串（长度需与第一个相同）："<< endl;
    cin.getline(s, 20);
    cout << "\n交换前：" << endl;
    cout << "字符串str：" << str << endl;
    cout << "字符串s：" << s << endl;
    for (int i = 0; str[i] != '\0' && s[i] != '\0'; i++) {
        temp = str[i];
        str[i] = s[i];
        s[i] = temp;
    }
    cout << "\n交换后：" << endl;
    cout << "字符串str：" << str << endl;
    cout << "字符串s：" << s << endl;
    return 0;
}