#include <cstdlib>
# include <iostream>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int length = rand()%9 + 1;
    cout<< length<<endl;
    int* arr = new int[length]; 
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 101;
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}