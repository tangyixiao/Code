#include <bits/stdc++.h>
using namespace std;

const int N = 3e1 + 5;

int n, p[N], q[N], rk[N], b[N], c[N], tb, tc, tot;
char h[N];
char fr[N], to[N];

inline void input() {
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        p[i] = s[i - 1] - 'a', q[i] = s[n - i] - 'a';
    }
    for (int i = 1; i <= n; ++i) {
        rk[q[i]] = i;
    }
}

inline void put(int x, char f, char t) {
    ++tot;
    h[tot] = x, fr[tot] = f, to[tot] = t;
}

inline void solve() {
    int i = 1, j = 1;
    while (j <= n) {
        if (tb && b[tb] == q[j]) {
            put(b[tb], 'B', 'D'), --tb, ++j;
        } else if (tc && c[tc] == q[j]) {
            put(c[tc], 'C', 'D'), --tc, ++j;
        } else if (i <= n && p[i] == q[j]) {
            put(p[i], 'A', 'D'), ++i, ++j;
        } else if (i <= n) {
            int x = tb ? rk[b[tb]] : N, y = tc ? rk[c[tc]] : N;
            if (x >= y) {
                b[++tb] = p[i], put(p[i], 'A', 'B');
            } else {
                c[++tc] = p[i], put(p[i], 'A', 'C');
            }
            ++i;
        } else {
            break;
        }
    }
    if (j <= n) {
        cout << "NO\n";
        return;
    }
    for (int k = 1; k <= tot; ++k) {
        cout << char(h[k] + 'a') << ' ' << fr[k] << ' ' << to[k] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
