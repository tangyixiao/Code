#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char s1[N], s2[N], s3[N];
int b;

inline long long cv(char *s) {
    long long x = 0;
    for (int i = 0; s[i]; ++i) {
        x = x * b + s[i] - '0';
    }
    return x;
}

inline void input() {
    cin >> s1 >> s2 >> s3;
}

inline void solve() {
    for (b = 2; b <= 40; ++b) {
        if (cv(s1) * cv(s2) == cv(s3)) {
            cout << b << "\n";
            return;
        }
    }
    cout << 0 << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}