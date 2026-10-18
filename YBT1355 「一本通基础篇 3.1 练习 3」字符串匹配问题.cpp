#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int n;
char s[N], st[N];

inline void input() {
    cin >> n;
    return;
}

inline char open(char c) {
    if (c == ')') {
        return '(';
    }
    if (c == ']') {
        return '[';
    }
    if (c == '}') {
        return '{';
    }
    return '<';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    for (int i = 0; i < n; i++) {
        cin >> s;
        int m = strlen(s), top = 0;
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (s[j] == ')' || s[j] == ']' || s[j] == '}' || s[j] == '>') {
                if (top == 0 || st[top - 1] != open(s[j])) {
                    ok = false;
                    break;
                }
                top--;
            } else {
                st[top++] = s[j];
            }
        }
        if (top) {
            ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}