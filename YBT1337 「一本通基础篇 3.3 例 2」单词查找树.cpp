#include <bits/stdc++.h>
using namespace std;

const int N = 32005;
int ch[N][30];
int n, tot;

inline void input() {
    return;
}

inline void solve() {
    tot = 1;
    string t;
    while (cin >> t) {
        int p = 0;
        for (size_t i = 0; i < t.size(); i++) {
            int c = t[i] - 'A';
            if (ch[p][c] == 0) {
                ch[p][c] = tot++;
            }
            p = ch[p][c];
        }
    }
    cout << tot << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}