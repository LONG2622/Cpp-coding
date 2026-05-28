//二分查找
#include<bits/stdc++.h>
using namespace std;
const int MAX=100010;
bool my_binary_search(const vector<int>& a,int right ,int left,int key){
    if(left > right) return false;  //如果左边界大于右边界，说明没有找到
    int mid = (left + right) >> 1;  //计算中间位置
    if(a[mid] > key){
        return my_binary_search(a, mid - 1, left, key);  //如果a[mid]大于key，说明答案在左边
    }
    else if(a[mid] < key){
        return my_binary_search(a, right, mid + 1, key);  //如果a[mid]小于key，说明答案在右边
    }
    else{
        return true;  //如果a[mid]等于key，说明找到了
    }
}
int main(){
    int N;
    int a[MAX];
    while(cin >> N){
        for(int i = 0 ; i < N; i++){
            cin >> a[i];
        }
        sort (a, a + N);  //对数组进行排序
        int key;
        cin >> key;
        if(binary_search(a, N - 1, 0, key)){
            cout << "YES" << endl;  //如果找到了，输出YES
        }
        else{
            cout << "NO" << endl;  //如果没有找到，输出NO
        }
    }
    return 0;
}