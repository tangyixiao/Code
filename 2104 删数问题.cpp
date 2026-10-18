#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int s, top, len;
char a[N], t[N], r[N];

inline void input() {
    cin >> t >> s;
    len = strlen(t);
    for (int i = 0; i < len; i++) {
        while (top > 0 && s > 0 && a[top - 1] > t[i]) {
            top--, s--;
        }
        a[top++] = t[i];
    }
    top -= s;
    for (int i = 0; i < top; i++) {
        r[i] = a[i];
    }
    r[top] = 0;
}

inline void solve() {
    int i = 0;
    while (i + 1 < top && r[i] == '0') {
        i++;
    }
    cout << r + i << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}