#include <bits/stdc++.h>
using namespace std;

const int N = 300;
int n;
char s[N];
char st[N];

int rk(char c) {
    if (c == '<') {
        return 0;
    }
    if (c == '(') {
        return 1;
    }
    if (c == '[') {
        return 2;
    }
    return 3;
}

char op(char c) {
    if (c == '>') {
        return '<';
    }
    if (c == ')') {
        return '(';
    }
    if (c == ']') {
        return '[';
    }
    return '{';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int t = 1; t <= n; t++) {
        cin >> s;
        int len = strlen(s), tp = 0, ok = 1;
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (c == '<' || c == '(' || c == '[' || c == '{') {
                st[tp++] = c;
            } else {
                if (tp == 0) {
                    ok = 0;
                    break;
                }
                if (st[tp - 1] != op(c)) {
                    ok = 0;
                    break;
                }
                if (tp >= 2) {
                    if (rk(st[tp - 2]) <= rk(st[tp - 1])) {
                        ok = 0;
                        break;
                    }
                }
                tp--;
            }
        }
        if (tp != 0) {
            ok = 0;
        }
        if (ok) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
