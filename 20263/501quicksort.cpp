#include<iostream>
#include<algorithm>
using namespace std;
void quicksort(int *a , int l ,int r){
    int i = 1 , j = r ,base = a[l];
    if(l < r){
        while(i != j){
            while(j > i && a[i] >= base){
                j --;
            }
            a[i] = a[j];
            while(j > i && a[i] <= base){
                i++;
            }
            a[j] = a[i];
        }
        a[i] = base;
        quicksort(a , l ,i - 1);
        quicksort(a, i ,r);
    }
}
int main(){

}