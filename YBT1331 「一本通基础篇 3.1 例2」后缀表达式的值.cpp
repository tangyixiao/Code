#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
int s[N];

inline void input() {
    return;
}

inline void apply(char c) {
    int y = s[--n], x = s[--n];
    if (c == '+') {
        s[n++] = x + y;
    } else if (c == '-') {
        s[n++] = x - y;
    } else if (c == '*') {
        s[n++] = x * y;
    } else {
        s[n++] = x / y;
    }
    return;
}

inline void solve() {
    n = 0;
    string t;
    while (cin >> t) {
        for (size_t i = 0; i < t.size(); i++) {
            char c = t[i];
            if (c == '@') {
                cout << s[0] << "\n";
                return;
            }
            if (c >= '0' && c <= '9') {
                int num = 0;
                while (c >= '0' && c <= '9') {
                    num = num * 10 + c - '0';
                    i++;
                    if (i >= t.size()) {
                        break;
                    }
                    c = t[i];
                }
                i--;
                s[n++] = num;
                continue;
            }
            if (c != '+' && c != '-' && c != '*' && c != '/') {
                continue;
            }
            apply(c);
        }
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