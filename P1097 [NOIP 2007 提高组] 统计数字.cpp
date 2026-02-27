#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int n, x;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (; n--;) {
        cin >> x;
        mp[x]++;
    }
    for (auto i : mp) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}