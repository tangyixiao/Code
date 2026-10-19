#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int a, b;
char s[N];

inline void input() {
    cin >> a >> b;
    return;
}

inline void solve() {
    a += b;
    int n = 0;
    for (; a; a /= 10) {
        s[n++] = a % 10 + '0';
    }
    if (!n) {
        s[n++] = '0';
    }
    for (int i = 0; i < n; i++) {
        if (i && (n - i) % 3 == 0) {
            cout << ",";
        }
        cout << s[n - 1 - i];
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
