#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

char buf[N];
int p, len, n, ans;

inline char gc() {
    if (p == len) {
        len = fread(buf, 1, N, stdin), p = 0;
    }
    return p < len ? buf[p++] : 0;
}

inline int rd() {
    int x = 0;
    char c = gc();
    for (; c < '0' || c > '9'; c = gc()) {
    }
    for (; c >= '0' && c <= '9'; c = gc()) {
        x = x * 10 + c - '0';
    }
    return x;
}

inline void input() {
    n = rd();
    for (int i = 1; i <= n; i++) {
        ans ^= rd();
    }
}

inline void solve() {
    printf("%d\n", ans);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
