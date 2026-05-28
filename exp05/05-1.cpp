#include<iostream>
using namespace std;
int main() {
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int fir = 0;
    int las = 9;
    while (fir < las) {
        while (fir < las && arr[fir] % 2 == 0) {
            fir++;
        }
        while (fir < las && arr[las] % 2 != 0) {
            las--;
        }   
        if (fir < las) {
            int temp = arr[fir];
            arr[fir] = arr[las];
            arr[las] = temp;
            fir++;
            las--;
    }
}
     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

return 0;
}