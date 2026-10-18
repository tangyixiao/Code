#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N], w[N];

inline void input() {
    cin.getline(w, N);
    cin.getline(s, N);
    for (int i = (int)strlen(w) - 1; i >= 0 && w[i] == '\r'; --i) {
        w[i] = 0;
    }
    for (int i = (int)strlen(s) - 1; i >= 0 && s[i] == '\r'; --i) {
        s[i] = 0;
    }
}

inline bool eq(int i) {
    for (int j = 0; w[j]; ++j) {
        char a = s[i + j], b = w[j];
        if (a >= 'A' && a <= 'Z') {
            a += 32;
        }
        if (b >= 'A' && b <= 'Z') {
            b += 32;
        }
        if (a != b) {
            return false;
        }
    }
    return s[i + strlen(w)] == ' ' || s[i + strlen(w)] == 0;
}

inline void solve() {
    int c = 0, f = -1;
    char p = ' ';
    for (int i = 0; s[i]; ++i) {
        if (p == ' ' && eq(i)) {
            ++c;
            if (f < 0) {
                f = i;
            }
        }
        p = s[i];
    }
    if (f < 0) {
        cout << -1 << "\n";
    } else {
        cout << c << " " << f << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
