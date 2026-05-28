#include<bits/stdc++.h>
using namespace std;
class person{
    protected:  string id;
    string name;
public:
 person(string i,string n ):id(i),name(n){}
 virtual void display() const{
    cout<<"编号"<<id<<"姓名"<<name<<endl;
 }
};
class Student : public person{
    private:string class_num;
    float score;
public:
Student(string i,string n,string c,float m):person(i,n),class_num(c),score(m){}
    void display() const override{
        person::display();
        cout<<"班级"<<class_num<<"  成绩"<<score<<endl;

    }

};
class teacher :public person{
    private:
    string department ;
    string title;
public:
teacher(string i,string n,string d ,string t):person(i,n),department(d),title(t){}
void display() const override {
        person::display();
        cout << "，部门：" << department << "，职称：" << title << endl;
    }
};


//测试函数
void testTask1() {
    cout << "===== 任务一 运行结果 =====" << endl;
    person p("P001", "张三");
    Student s("S001", "李四", "计科2班", 92.5);
    teacher t("T001", "王五", "机械学院", "教授");
    
    p.display(); cout << endl;
    s.display();
    t.display();
    cout << endl;
}

int main() {
    testTask1();  // 调用测试函数
    return 0;     // 程序正常退出
}