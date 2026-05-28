#include<iostream>
using namespace std;
class circle{
    protected:
    float r;
public:
circle(float r):r(r){}
float areaS() const{
    return 3.14*r*r;
}
};
class table{
    protected:
    float height;
    string color;
    public:
    table(float h,string c):height(h),color(c){}
    float getheight() const {return height;}
    string getcolor() const {return color;}
};
class roundtable:public table,public circle {
public:
roundtable(float r,float h,string c):circle(r),table(h,c){}
void display() const{
    cout << "圆桌高度：" << getheight() << "m" << endl;
        cout << "圆桌颜色：" << getcolor() << endl;
        cout << "桌面面积：" << areaS() << "m²" << endl;
}
};
void testTask2() {
    cout << "===== 任务二 运行结果 =====" << endl;
    roundtable rt(1.2, 0.75, "深棕色");
    rt.display();
    cout << endl;
}
int main(){
    testTask2();
    return 0;
}