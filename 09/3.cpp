#include<iostream>
#include<cstring>
using namespace std;
class charplus{
private:
        char*str;
public:
    charplus(const char *s=""){
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    ~charplus(){
        delete[] str;
    }
    charplus(const charplus &other){
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
    charplus& operator=(const charplus &other){
        if(this == &other){
            return *this;        }
        delete[] str;
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
        return *this;}
    charplus& operator+=(const charplus &other){
        int len1 = strlen(str);
        int len2 = strlen(other.str);
        char* temp = new char[len1 + len2 + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        delete[] str;
        str = temp;
        return *this;}
    void display(){
        cout<<str<<endl;}
};  
int main(){
    charplus str1("Hello!");
    charplus str2("you are Welcome");
    cout<<"原始str1:";str1.display();
    cout<<"原始str2:";str2.display();
    str1 += str2;
    cout<<"str1 += str2 后:";    str1.display();
    return 0;
}