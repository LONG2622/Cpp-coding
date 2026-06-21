#include<iostream>
using namespace std;
const char *f(const char *s){
    if(*s){//如果s指向的字符不是'\0'，则继续递归调用f函数，并将s指向下一个字符
        cout << *f(s + 1) ;//递归调用f函数，并将s指向下一个字符，直到s指向'\0'，此时返回s - 1，即最后一个字符的地址
    }
        return s - 1;//当s指向'\0'时，返回s - 1，即最后一个字符的地址
}
int main(){//主函数
    f("program");//调用f函数，并传入字符串"program"，此时s指向字符串的第一个字符'p'
    return 0;
}