#include <iostream>
using namespace std;
int main()
{
    int arr[100], brr[100];
    int n, m;
    cout << "input number of arr(max 100): ";
    cin >> n;
    cout << "input number of brr(max 100): ";
    cin >> m;
    for(int i = 0; i < n; i++)
    {
        cout << "input arr[" << i << "]: ";
        cin >> arr[i]; 
    }
    for(int j = 0; j < m; j++){
        cout << "input brr[" << j << "]: ";
        cin >> brr[j];
    }
    cout << "一样的数有: ";
    for(int i = 0; i < n; i++)
    {
        bool already_used = false;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] == arr[i])
            {
                already_used = true;
                break;
            }
        }
        if(already_used) continue;
        for(int j = 0; j < m; j++)
        {
            if(arr[i] == brr[j])
            {
                cout << arr[i] << " ";
                break;
            }
        }
    }
    return 0;
}