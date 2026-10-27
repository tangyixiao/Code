#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size(), ne = (n + 1) / 2, no = n / 2;
    string t = s.substr(0, ne);
    reverse(t.begin(), t.end());
    string u = s.substr(ne, no);
    string r;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            r += t[i / 2];
        } else {
            r += u[i / 2];
        }
    }
    cout << r << "\n";
    return 0;
}
