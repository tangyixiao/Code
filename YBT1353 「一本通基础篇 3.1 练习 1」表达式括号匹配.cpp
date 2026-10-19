#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char s[N];
int st[N], top;

inline void input() {
    cin >> s;
}

inline void solve() {
    for (int i = 0; s[i] && s[i] != '@'; ++i) {
        if (s[i] == '(') {
            st[top++] = i;
        } else if (s[i] == ')') {
            if (top == 0) {
                cout << "NO\n";
                return;
            }
            --top;
        }
    }
    cout << (top == 0 ? "YES\n" : "NO\n");
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
