#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int n;
char s[N], st[N];

inline void input() {
    cin >> s;
    n = strlen(s);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    int top = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st[top++] = ')';
        } else if (s[i] == '[') {
            st[top++] = ']';
        } else if (top == 0 || st[top - 1] != s[i]) {
            cout << "Wrong\n";
            return 0;
        } else {
            top--;
        }
    }
    cout << (top ? "Wrong\n" : "OK\n");
    return 0;
}