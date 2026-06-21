#include<iostream>
#include<string>
using namespace std;
string f1(string str,string add){
    str += add;
    return str;
}
string f2(int a,int b,string str1){
    return str1.substr(a,b);
}
string f3(string str1,int a,string str){
    string left = str1.substr(0, a);        // 0~a-1
    string right = str1.substr(a);          // a~结尾
    return left + str + right;
}
int f4(string str, string a){
    int pos = str.find(a);
    if (pos == string::npos) return -1;
    return pos;
}
int main(){
    int n; 
    cin >> n;
    string str;
    cin >> str;
    for(int i = 0;i < n ;i ++){
        int x;
        cin >> x;
        if(x == 1){
            string add;
            cin >> add;
            str = f1(str,add);
            cout<< str << endl;
        }
        else if(x == 2){
            int a,b;
            cin >> a >> b;
            str = f2(a,b,str);
            cout << str << endl;
        }
        else if(x == 3){
            int a;
            string add;
            cin >> a >> add;
            str = f3(str,a,add);
            cout << str << endl;
        }
        else if(x == 4){
            string a;
            cin >> a;
            cout << f4(str,a) << endl;
        }
    }
    return 0;
}