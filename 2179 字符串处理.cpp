#include <bits/stdc++.h>
using namespace std;

string s;

inline void solve() {
    int q;
    cin >> q >> s;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            string t;
            cin >> t;
            s += t;
            cout << s << "\n";
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            s = s.substr(a, b);
            cout << s << "\n";
        } else if (op == 3) {
            int a;
            string t;
            cin >> a >> t;
            s.insert(a, t);
            cout << s << "\n";
        } else {
            string t;
            cin >> t;
            size_t p = s.find(t);
            cout << (p == string::npos ? -1 : (int)p) << "\n";
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}