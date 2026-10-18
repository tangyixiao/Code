#include <bits/stdc++.h>
using namespace std;

const int N = 4e1 + 5;

int n;
char s[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    int t = 0;
    for (; n; n >>= 1) {
        s[++t] = char('0' + (n & 1));
    }
    for (int i = t; i >= 1; i--) {
        cout << s[i];
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
