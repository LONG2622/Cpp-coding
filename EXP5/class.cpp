#include <iostream>
#include <string>
using namespace std;
class Student{
    public:
    string m_name;
    int m_id;
    void setName(string name){
        m_name = name;

    }
void setID (int id){
    m_id = id;
}
void showStudent(){
    cout << "name:" << m_name << " id:" << m_id << endl; // 加了空格和冒号，还加了换行
}
};
int main(){
    Student s1;
    s1.m_name ="tom";
    s1.m_id = 3024;
    s1.showStudent();
    return 0;
}
