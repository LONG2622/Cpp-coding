#include <cstring>
#include <iostream>
using namespace std;
class charplus{
private:
        char*str;
        friend charplus& operator+=(charplus &lhs, const charplus &rhs);
public:
    charplus(const char *s=""){
        str = new char[strlen(s) + 1];
        strcpy(str, s);}
    ~charplus(){
        delete[] str;}
    charplus &operator=(const charplus &other){
        if(this == &other){
            return *this;        }
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str,other.str);
    return *this;}
    void display(){
        cout<<str<<endl;}
    const char* getStr() const {
        return str;}
};
charplus& operator+=(charplus &lhs, const charplus &rhs){
    int len1 = strlen(lhs.str);
    int len2 = strlen(rhs.str);
    char* temp = new char[len1 + len2 + 1];
    strcpy(temp, lhs.str);
    strcat(temp, rhs.str);
    delete[] lhs.str;
    lhs.str = temp;
    return lhs;}
int main(){
    charplus str1("Hello!");
    charplus str2(" you are Welcome");
    cout<<"原始str1:";str1.display();
    cout<<"原始str2:";str2.display();
    str1 += str2;
    cout<<"str1 += str2 后:";    str1.display();
    return 0;}