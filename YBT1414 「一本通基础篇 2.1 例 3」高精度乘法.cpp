#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;
int a[N], c1[N], c2[N], l1, l2;

inline void input() {}

inline void solve() {
    string s, t;
    cin >> s >> t;
    l1 = s.size(), l2 = t.size();
    memset(c1, 0, sizeof c1), memset(c2, 0, sizeof c2);
    for (int i = 0; i < l1; ++i) {
        a[i] = s[l1 - 1 - i] - '0';
    }
    for (int i = 0; i < l2; ++i) {
        c2[i] = t[l2 - 1 - i] - '0';
    }
    for (int i = 0; i < l1; ++i) {
        for (int j = 0; j < l2; ++j) {
            c1[i + j] += a[i] * c2[j];
        }
    }
    for (int i = 0; i + 1 < l1 + l2; ++i) {
        c1[i + 1] += c1[i] / 10;
        c1[i] %= 10;
    }
    int h = l1 + l2 - 1;
    while (h > 0 && !c1[h]) {
        --h;
    }
    for (int i = h; i >= 0; --i) {
        cout << c1[i];
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}