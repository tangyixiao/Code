#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;
char s[N], t[N];

inline void input() {
    cin >> n >> s;
    for (int i = 0; i < n * 3; i++) {
        t[i] = s[i % n];
    }
}

int rd(int i) {
    char c = 0;
    int cnt = 0;
    for (int k = 0; k < n; k++) {
        char x = t[i - 1 - k];
        if (c == 0) {
            if (x != 'w') {
                c = x;
            }
        } else if (x != c && x != 'w') {
            break;
        }
        cnt++;
    }
    return cnt;
}

int lu(int i) {
    char c = 0;
    int cnt = 0;
    for (int k = 0; k < n; k++) {
        char x = t[i + k];
        if (c == 0) {
            if (x != 'w') {
                c = x;
            }
        } else if (x != c && x != 'w') {
            break;
        }
        cnt++;
    }
    return cnt;
}

inline void solve() {
    int mx = 0;
    for (int i = n; i < n * 2; i++) {
        mx = max(mx, min(n, lu(i) + rd(i)));
    }
    cout << mx << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
