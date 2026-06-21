#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll L;
    int n , m ;
    cin >> n >> m;
    vector<long long> rock;
    rock.push_back(0);
    for(int i = 0 ; i < n ;i ++){
        ll d;
        cin >> d;
        rock.push_back(d);
    }
    rock.push_back(L);
    sort(rock.begin(),rock.end());
    ll left = 1;
    ll right = L;
    ll Max = 0;
    while(left <= right){
        ll mid = (left + right) / 2;
        int remo = 0;
        int last = 0;
        for(int i = 1 ;i < rock.size();i++){
            if(rock[i] - rock[last] < mid ){
                remo ++;
            }
            else{
                last = i;
            }
        }
            if (remo <= m) {
            Max = mid;
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }
    cout << Max;
}