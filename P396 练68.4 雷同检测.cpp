#include <bits/stdc++.h>
using namespace std;

string a, b;

inline void input() {
    getline(cin, a), getline(cin, b);
    return;
}

inline void solve() {
    for (int i = 0; i < (int)a.size() && i < (int)b.size(); i++) {
        if (a[i] == b[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
