#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 26 + 5;

char s[N];
int c[M], n;

inline void input() {
    cin >> s;
    n = strlen(s);
}

inline void solve() {
    for (int i = 0; i < n; ++i) {
        ++c[s[i] - 'a'];
    }
    int k = 0;
    for (int i = 1; i < 26; ++i) {
        if (c[i] > c[k]) {
            k = i;
        }
    }
    cout << char('a' + k) << " " << c[k] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
