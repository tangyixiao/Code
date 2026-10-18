#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int b, ans[N];

inline void input() {
    cin >> b;
}

string cv(int x) {
    string s;
    const string d = "0123456789ABCDEFGHIJ";
    for (; x; x /= b) {
        s = d[x % b] + s;
    }
    return s;
}

inline void solve() {
    for (int i = 1; i <= 300; i++) {
        string s = cv(i * i), t = s;
        for (int l = 0, r = (int)s.size() - 1; l < r; l++, r--) {
            swap(s[l], s[r]);
        }
        if (s == t) {
            cout << cv(i) << " " << t << "\n";
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
