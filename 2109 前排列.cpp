#include <bits/stdc++.h>
using namespace std;

const int N = 25;

string s, t;

inline void input() {
    cin >> s;
}

inline void solve() {
    int n = s.size(), i = n - 2;
    for (; i >= 0 && t[i] <= t[i + 1]; --i) {
    }
    t = s;
    i = n - 2;
    for (; i >= 0 && t[i] <= t[i + 1]; --i) {
    }
    if (i < 0) {
        cout << -1 << "\n";
        return;
    }
    int j = n - 1;
    for (; j > i; --j) {
        if (t[j] < t[i]) {
            break;
        }
    }
    swap(t[i], t[j]);
    for (int l = i + 1, r = n - 1; l < r; ++l, --r) {
        swap(t[l], t[r]);
    }
    int p = 0;
    for (; p < n - 1 && t[p] == '0'; ++p) {
    }
    cout << t.substr(p) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
