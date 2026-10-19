#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;
string a[N], buf, t;

inline void input() {
    getline(cin, buf);
    n = 0;
    stringstream ss(buf);
    while (ss >> t) {
        a[n++] = t;
    }
}

inline void solve() {
    input();
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            cout << a[i] << "\n";
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