#include <bits/stdc++.h>
using namespace std;

const int N = 10 + 5;

char s[N][N];
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    do {
        for (int i = 0; i < n; i++) {
            cout << (i ? " " : "") << s[a[i]];
        }
        cout << "\n";
    } while (next_permutation(a, a + n));
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}