#include <iostream>
#include <string>
using namespace std;

class Father {
protected:
    string familyName; 
    string givenName;  
public:
    Father(string f, string g) : familyName(f), givenName(g) {}
    string getFullName() const {
        return familyName + givenName;
    }
};

// 基类2：母亲类
class Mother {
protected:
    string familyName; // 姓
    string givenName;  // 名
public:
    Mother(string f, string g) : familyName(f), givenName(g) {}
    string getFullName() const {
        return familyName + givenName;
    }
};

class Child : public Father, public Mother {
private:
    string givenName; // 子女的名（姓继承自父亲）
public:
    // 构造函数（调用父母类构造）
    Child(string f_family, string f_given,  // 父亲姓名
          string m_family, string m_given,  // 母亲姓名
          string c_given)                   // 子女的名
        : Father(f_family, f_given), 
          Mother(m_family, m_given), 
          givenName(c_given) {}
    
    // 显示全家姓名
    void displayFamily() const {
        cout << "父亲姓名：" << Father::getFullName() << endl;
        cout << "母亲姓名：" << Mother::getFullName() << endl;
        cout << "子女姓名：" << Father::familyName << givenName << endl;
    }
};

// 任务三测试函数
void testTask3() {
    cout << "===== 任务三 运行结果 =====" << endl;
    // 父亲：张 三，母亲：李 四，子女：小明
    Child child("张", "三", "李", "四", "小明");
    child.displayFamily();
    cout << endl;
}
int main(){
    testTask3();
    return 0;
}