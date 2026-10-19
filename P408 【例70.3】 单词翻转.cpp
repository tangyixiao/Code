#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;

char s[N];

inline void input() {
    cin.getline(s, sizeof(s));
}

inline void solve() {
    int n = strlen(s);
    string r;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            r += ' ';
        } else {
            int j = i;
            while (j < n && s[j] != ' ') {
                j++;
            }
            for (int k = j - 1; k >= i; k--) {
                r += s[k];
            }
            i = j - 1;
        }
    }
    cout << r << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}