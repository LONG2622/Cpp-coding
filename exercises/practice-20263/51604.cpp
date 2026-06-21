#include<iostream>
using namespace std;

// 最大公因数（辗转相除法）
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        return gcd(a , b);
    }
    return a;
}
int lcm(int a, int b){
    return a / gcd(a,b) * b ;
}
// 最小公倍数
int lcm(int a, int b) {
    return a / gcd(a, b) * b;  // 先除后乘，防止溢出
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    return 0;
}
#include<iostream>
using namespace std;
int lcm(int x ,int y){
    return x / gcd(x, y) * y;
}
int gcd(int a, int b){
    int temp;
    if(b){
        temp = b ;
        b = a % b;
        a =temp;
        return gcd(a , b);
    }
    return a;
}