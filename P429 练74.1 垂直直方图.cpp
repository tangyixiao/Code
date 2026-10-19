#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char l[N];
int c[26];

inline void input() {
    for (int i = 0; i < 4; i++) {
        cin.getline(l, sizeof(l));
        int m = strlen(l);
        for (int j = 0; j < m; j++) {
            if (l[j] >= 'A' && l[j] <= 'Z') {
                c[l[j] - 'A']++;
            }
        }
    }
}

inline void solve() {
    int mx = 0;
    for (int i = 0; i < 26; i++) {
        mx = max(mx, c[i]);
    }
    for (int i = mx; i >= 1; i--) {
        for (int j = 0; j < 26; j++) {
            cout << (c[j] >= i ? '*' : ' ');
            if (j < 25) {
                cout << ' ';
            }
        }
        cout << "\n";
    }
    for (int j = 0; j < 26; j++) {
        cout << char('A' + j);
        if (j < 25) {
            cout << ' ';
        }
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}