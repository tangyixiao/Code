#include <bits/stdc++.h>
using namespace std;

const int N = 1e1 + 5;

char s[N];
int n;

inline void input() {
    cin >> s;
    n = strlen(s);
}

inline void solve() {
    sort(s, s + n);
    do {
        cout << s << "\n";
    } while (next_permutation(s, s + n));
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
