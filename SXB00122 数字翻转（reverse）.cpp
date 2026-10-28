#include <bits/stdc++.h>
using namespace std;

inline char rot(char c) {
    if (c == '6') {
        return '9';
    }
    if (c == '9') {
        return '6';
    }
    return c;
}

signed main() {
    long long m, n;
    cin >> m >> n;
    for (long long x = m; x <= n; x++) {
        string s = to_string(x), t;
        int ok = 1;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c != '0' && c != '1' && c != '6' && c != '8' && c != '9') {
                ok = 0;
                break;
            }
            t += rot(c);
        }
        if (ok && t == s) {
            cout << x << "\n";
        }
    }
    return 0;
}
