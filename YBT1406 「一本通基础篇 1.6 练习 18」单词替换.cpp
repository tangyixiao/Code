#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char s[N], a[N], b[N], t[N];

inline void input() {
    cin.getline(s, N);
    cin >> a >> b;
    return;
}

inline void solve() {
    int p = 0, l = 0, fst = 1, n = strlen(s);
    while (p < n) {
        while (p < n && s[p] == ' ') {
            p++;
        }
        if (p >= n) {
            break;
        }
        l = p;
        while (p < n && s[p] != ' ') {
            p++;
        }
        int c = p - l;
        memcpy(t, s + l, c);
        t[c] = 0;
        if (!strcmp(t, a)) {
            strcpy(t, b);
        }
        if (!fst) {
            cout << " ";
        }
        cout << t;
        fst = 0;
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
