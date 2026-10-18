#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

char s[N], t[N];
int k, c;

void solve();

inline void input() {
    cin >> c;
    for (int i = 0; i < c; ++i) {
        cin >> s >> k;
        solve();
    }
    return;
}

inline void solve() {
    int n = strlen(s), top = 0;
    for (int i = 0; i < n; ++i) {
        while (top && k && t[top - 1] > s[i]) {
            --top, --k;
        }
        t[top++] = s[i];
    }
    t[top - k] = 0;
    cout << t << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    return 0;
}
