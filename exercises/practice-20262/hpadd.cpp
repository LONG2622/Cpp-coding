#include<iostream>
#include<vector>
using namespace std;
vector<int> high_precision_add(vector<int> a, vector<int> b){
    vector<int> c;
    int temp = 0;
    for(int i = 0 ; i < a.size() || i < b.size() || temp != 0; i++){
        if(i < a.size()) temp += a[i];
        if(i < b.size()) temp += b[i];
        c.push_back(temp % 10);
        temp /= 10;
    }
    return c;
}
int  main(){
    vector<int>a;
    vector<int>b;
    high_precision_add(a,b);
    return 0;
}