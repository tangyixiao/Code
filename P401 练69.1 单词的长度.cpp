#include <bits/stdc++.h>
using namespace std;

string s, w;

inline void input() {
    getline(cin, s);
    return;
}

inline void solve() {
    stringstream ss(s);
    bool f = true;
    while (ss >> w) {
        if (f) {
            f = false;
        } else {
            cout << ",";
        }
        cout << w.size();
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
