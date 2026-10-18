#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char a[N], b[N];

inline long long cv(char *s) {
    int h = (s[0] - '0') * 10 + s[1] - '0';
    int m = (s[3] - '0') * 10 + s[4] - '0';
    int t = (s[6] - '0') * 10 + s[7] - '0';
    int c = (s[9] - '0') * 10 + s[10] - '0';
    return ((h * 60 + m) * 60 + t) * 100 + c;
}

inline void input() {
    cin >> a >> b;
}

inline void solve() {
    cout << llabs(cv(b) - cv(a)) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
