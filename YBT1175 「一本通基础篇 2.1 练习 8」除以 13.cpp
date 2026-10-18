#include <bits/stdc++.h>
using namespace std;

const int N = 30 + 5;
char s[N];
int a[N], n;

inline void input() {
    cin >> s;
    return;
}

inline void solve() {
    for (int i = 0; s[i]; i++) {
        a[++n] = s[i] - '0';
    }
    int r = 0, p = n + 1;
    for (int i = 1; i <= n; i++) {
        int v = r * 10 + a[i];
        a[i] = v / 13, r = v % 13;
        if (a[i] && p == n + 1) {
            p = i;
        }
    }
    if (p == n + 1) {
        cout << "0\n";
    }
    for (int i = p; i <= n; i++) {
        cout << a[i];
    }
    cout << "\n"
         << r << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}