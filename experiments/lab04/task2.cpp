#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    int arr[6];
    for (int j = 0; j < 6; j++) {
        cin >> arr[j];
    }
    for(int i = 0; i < 6; i++) {
        sum += arr[i];
    }
    cout << sum << endl;
    return 0;
}