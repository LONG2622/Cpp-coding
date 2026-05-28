#include <iostream>
#include <cstring> 
using namespace std;

int main() {
    char* str = nullptr;
    char* s = nullptr;
    char temp;
    cout << "请输入第一个字符串：";
    char buffer[1000];  
    cin.getline(buffer, 1000);
    int len = strlen(buffer); 
    str = new char[len + 1];
    strcpy(str, buffer);
    cout << "请输入第二个字符串（长度需与第一个相同）：";
    cin.getline(buffer, 1000);
    if (strlen(buffer) != len) {
        delete[] str;
        return 1;
    }
    s = new char[len + 1];
    strcpy(s, buffer);
    cout << "\n交换前：" << endl;
    cout << "str: " << str << endl;
    cout << "s: " << s << endl;
    for (int i = 0; i < len; i++) {
        temp = *(str + i);
        *(str + i) = *(s + i);
        *(s + i) = temp;
    }
    cout << "\n交换后：" << endl;
    cout << "str: " << str << endl;
    cout << "s: " << s << endl;
    delete[] str;
    delete[] s;
    str = nullptr; 
    s = nullptr;
    return 0;
}
