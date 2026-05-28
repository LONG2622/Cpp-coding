#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t --){
        int m ,n ;
        cin >> m >> n;
        int las = 0;
        int fis = 0;
        for(int i = 0; i < n ; i ++){
            int pos = 0; 
            int lef = pos;
            int rig = m - pos;
            fis = max(fis , min(lef,rig));
            las = max(las , max(lef,rig));
        }
        cout << fis << " " << las << endl;
    }
}