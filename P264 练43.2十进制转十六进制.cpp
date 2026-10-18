#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
char c[] = "0123456789ABCDEF", s[15];

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    input();
    int t = 0;
    for (; n; n /= 16) {
        s[t++] = c[n % 16];
    }
    for (int i = t - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");
    return;
}

signed main() {
    solve();
    return 0;
}