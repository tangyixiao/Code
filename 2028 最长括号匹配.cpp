#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

string s;
int f[N], len, pos;

inline bool mtc(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

inline void input() {
    cin >> s;
}

inline void solve() {
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '(' || s[i - 1] == '[') {
            continue;
        }
        int j = i - f[i - 1] - 1;
        if (j < 1 || !mtc(s[j - 1], s[i - 1])) {
            continue;
        }
        f[i] = f[i - 1] + 2 + f[j - 1];
        if (f[i] > len) {
            len = f[i], pos = i - f[i];
        }
    }
    cout << s.substr(pos, len) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
