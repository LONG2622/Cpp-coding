#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int arr[13] = { 0 , 2 , 5 , 5 , 1 , 3 , 6 , 1 , 4 , 0 , 2 , 5 , 0 };
    //int arr[13] = { 0 , 3 , 6 , 6 , 2 , 4 , 7 , 2 , 5 , 1 , 3 , 6 , 1 };
    int d[13] = { 0 , 31, 28 ,31 , 30 , 31 , 
        30 , 31 , 31 , 30 ,31 , 30 , 31};
    /*int m ;
    cin >> m ;*/
    cout << "MON TUE WED THU FRI SAT SUN" << endl;
    for(int m = 1; m <= 12; m++){
    for(int j = 0 ; j < arr[m] ;j ++){
        cout << "    ";
    }
    for(int i = 1 ; i <= d[m] ;i++){
        cout << setw(3) << i << " ";
        if((i + arr[m] ) % 7 == 0 ){
            cout << endl;
        }
    }
    cout << endl;
}
    return 0;
}