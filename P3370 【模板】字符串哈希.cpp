#include <bits/stdc++.h>
using namespace std;
string s;
map<string, int> mp;
int n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> s;
        mp[s]++;
    }
    cout << mp.size() << '\n';
    return 0;
}