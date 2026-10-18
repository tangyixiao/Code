#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 5;

int a[4], b[3];
string s;

inline void input() {
    cin >> a[0] >> a[1] >> a[2] >> s;
    sort(a, a + 3);
}

inline void solve() {
    for (int i = 0; i < 3; i++) {
        cout << a[s[i] - 'A'] << (i == 2 ? "\n" : " ");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
