#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[1005];
    for(int i =  0 ; i < n ; i++){
        int len , m;
        int min = 0;
        int max = 0;
        cin >> len >> m;
        for(int j = 0 ; j < m;j++){
            cin >> a[j];
            int near = min(a[j], len - a[j]);
            int far = max(a[j], len - a[j]);
            if(near > min)
                min = near;
            if(far > max)
                max = far;
        }
     cout << min << " " << max << endl;
    }
    return 0;
}