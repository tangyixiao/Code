#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, c[N], b[N];
char s[N];

inline bool cmp(int x, int y) {
    if (c[x] != c[y]) {
        return c[x] > c[y];
    }
    return x < y;
}

inline void input() {
    cin >> s;
    n = 0;
    for (int i = 0; i < 26; i++) {
        b[n++] = i;
    }
}

inline void solve() {
    input();
    for (int i = 0; s[i]; i++) {
        int t = s[i];
        if (t >= 'a' && t <= 'z') {
            t -= 32;
        }
        if (t >= 'A' && t <= 'Z') {
            c[t - 'A']++;
        }
    }
    sort(b, b + n, cmp);
    for (int i = 0; i < n; i++) {
        if (c[b[i]]) {
            cout << (char)(b[i] + 'A') << " " << c[b[i]] << "\n";
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