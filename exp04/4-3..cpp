#include <iostream>
using namespace std;

int main() {
    const int maxSIZE = 1000;
    char str[maxSIZE];
    cout << "请输入一个字符串：";
    cin.getline(str, maxSIZE); 
    int count_a = 0;
    int count_i = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            count_a++;
        } else if (str[i] == 'i') {
            count_i++;
        }
    }
    cout << "输入的字符串是：" << str << endl;
    cout << "其中小写字母'a'的个数是：" << count_a << endl;
    cout << "其中小写字母'i'的个数是：" << count_i << endl;
    
    return 0;
}
