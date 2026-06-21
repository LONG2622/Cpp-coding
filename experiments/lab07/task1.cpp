#include <iostream>
using namespace std;

// 定义Integer整型类
class Integer {
private:
    int d; // 私有数据成员d

public:
    // 构造函数（默认初始化d为0）
    Integer() : d(0) {}

    // 设置d的值
    void setD(int value) {
        d = value;
    }

    // 获取d的值
    int GetD() {
        return d;
    }

    // 判断d是否为偶数（题目中IsOdd命名可能笔误，按功能实现偶数判断）
    bool IsOdd() {
        return d % 2 == 0; // 偶数返回true，奇数返回false
    }

    // 判断d是否为素数
    bool IsPrime() {
        if (d <= 1) return false; // 小于等于1的数不是素数
        if (d == 2) return true;  // 2是素数
        if (d % 2 == 0) return false; // 偶数（除2外）不是素数
        // 检查从3到sqrt(d)的奇数是否能整除d
        for (int i = 3; i * i <= d; i += 2) {
            if (d % i == 0) return false;
        }
        return true;
    }
};

// 主函数测试
int main() {
    Integer obj; 
    
    obj.setD(15);
    cout << "测试值d = " << obj.GetD() << ":" << endl;
    cout << "是否为偶数？" << (obj.IsOdd() ? "是" : "否") << endl;
    cout << "是否为素数？" << (obj.IsPrime() ? "是" : "否") << endl << endl;

    obj.setD(31);
    cout << "测试值d = " << obj.GetD() << ":" << endl;
    cout << "是否为偶数？" << (obj.IsOdd() ? "是" : "否") << endl;
    cout << "是否为素数？" << (obj.IsPrime() ? "是" : "否") << endl;

    return 0;
}