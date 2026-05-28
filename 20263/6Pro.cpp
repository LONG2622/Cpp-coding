#include<iostream>//采用动态数组，vector<int>，来存储大数，避免了数组长度的限制。
#include<vector>//使用vector<int>来存储大数，每个元素代表大数的一位，方便进行加法运算。
using namespace std;//高精度加法：定义一个函数add，用于将两个大数相加，返回结果也是一个大数。
vector<int> add(vector<int> a , vector<int> b){//使用一个临时变量temp来存储每一位的和，以及进位。遍历两个大数的每一位，进行加法运算，并处理进位。最后返回结果。
    vector<int> c;
    int temp = 0;//遍历两个大数的每一位，进行加法运算，并处理进位。
    for(int i = 0 ; i < a.size() || i < b.size() || temp != 0; i++){
        if(i < a.size()) temp += a[i];
        if(i < b.size()) temp += b[i];
        c.push_back(temp % 10);//将当前位的结果存储在结果大数的对应位置。
        temp /= 10;
    }
    return c;
}
void print(vector<int> a){//定义一个函数print，用于输出大数。遍历大数的每一位，从高位到低位输出，最后换行。
    for(int i = a.size() - 1 ; i >= 0 ; i--){
        cout << a[i];//从高位到低位输出，最后换行。
    }
    cout << endl;
}
int main(){
    int n ;
     cin >> n;
     vector<int> f1(1,1);
     vector<int> f2(1,2);
     vector<int>f3;
    if(n == 1){
        return 1;}
    if(n == 2){
        return 2;}
    for(int i = 3 ;i <= n;i++){
        f3 = add(f1 , f2);//将当前位的结果存储在结果大数的对应位置。
        f1 = f2;        
        f2 = f3;
    }
    print(f2);//输出结果。
    return 0;
}