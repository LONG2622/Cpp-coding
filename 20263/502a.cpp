#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    ll l, n , m;
    cin >> l >> n >> m;
    vector<ll> rock;
    rock.push_back(0);
    for(int i = 0 ; i < n ; i++){
        ll d;
         cin >>d;
        rock.push_back(d);
    }
    rock.push_back(l);
    sort(rock.begin(),rock.end());
    ll left = 1;
    ll right = l;
    ll ma = 0;
    while(left <= right){
        ll mid = (left + right) / 2;
        int rem = 0 ;
        int las = 0 ;
        for(int i = 1 ; i < rock.size(); i++){
            if(rock[i] - rock[las] < mid){
                rem++;
            }
            else{
                las = i;
            }
        }
    if(rem <= m){
        ma = mid;
        left = mid + 1;
    }
    else{
        right = mid - 1;
    }
}
cout << ma;
return 0 ;
}