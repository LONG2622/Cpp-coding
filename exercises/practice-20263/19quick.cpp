#include<iostream>
using namespace std;
//quick sort
void quick_sort(int a[], int l, int r){
    if(l >= r) return;
    int pivot = a[l]; // 选择第一个元素作为基准
    int i = l, j = r;
    while(i < j){
        while(i < j && a[j] >= pivot) j--; // 从右向左找小于基准的元素
        if(i < j) a[i++] = a[j]; // 将找到的元素放到左边
        while(i < j && a[i] <= pivot) i++; // 从左向右找大于基准的元素
        if(i < j) a[j--] = a[i]; // 将找到的元素放到右边
    }
    a[i] = pivot; // 将基准元素放到正确的位置
    quick_sort(a, l, i - 1); // 递归排序左半部分
    quick_sort(a, i + 1, r); // 递归排序右半部分
}
int main(){
    int n;
    cin >> n;
    int a[100010];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
    return 0;
}