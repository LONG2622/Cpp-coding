#include<iostream>
#include<vector>
using namespace std;
int josephus(int n, int k) {
    vector<int> people;
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }
    int pos = 0;
    while (people.size() > 1) {
        pos = (pos + k - 1) % people.size();
        people.erase(people.begin() + pos);
    }
    return people[0];
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k;
        cin >> n >> k;
        int ans = josephus(n, k);
        cout << "Case " << t << ": " << ans << endl;
    }
    return 0;
}