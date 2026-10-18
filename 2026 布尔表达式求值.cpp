#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

string s;
int p;

inline int expr();

inline int atom() {
    if (s[p] == '!') {
        p++;
        return !atom();
    }
    if (s[p] == '(') {
        p++;
        int v = expr();
        p++;
        return v;
    }
    return s[p++] - '0';
}

inline int term() {
    int v = atom();
    while (p < (int)s.size() && s[p] == '&') {
        p++, v &= atom();
    }
    return v;
}

inline int expr() {
    int v = term();
    while (p < (int)s.size() && s[p] == '|') {
        p++, v |= term();
    }
    return v;
}

inline void input() {
    cin >> s;
}

inline void solve() {
    cout << expr() << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}