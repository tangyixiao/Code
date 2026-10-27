#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

signed main() {
    int n, m, p;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s >> p;
        mp[s] = p;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s;
        cout << mp[s] << "\n";
    }
    return 0;
}
