#include<iostream>
using namespace std;
int transform(int n) {
    int a[1000] = {0};
    int i = 0;  
    while (n) {
        a[i] = n % 2;
        i++; 
        n /= 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << a[j];
    }
    return 0;
}