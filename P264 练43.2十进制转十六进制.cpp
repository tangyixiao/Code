#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, x, ans;
char c[] = "0123456789ABCDEF";

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    input();
    for (; n; n /= 16) ans = ans * 16 + n % 16;
    int t = ans, len = 0;
    while (t) len++, t /= 10;
    for (int i = len; i; i--) printf("%c", c[ans / pow(10, i - 1) % 10]);
    printf("\n");
    return;
}

signed main() {
    solve();
    return 0;
}