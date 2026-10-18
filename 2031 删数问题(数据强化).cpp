#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

string s;
char st[N];
int m, top;

inline void input() {
    cin >> s >> m;
    top = 0;
}

inline void solve() {
    for (int i = 0; i < (int)s.size(); i++) {
        while (top && m && st[top - 1] > s[i]) {
            top--, m--;
        }
        st[top++] = s[i];
    }
    while (m) {
        top--, m--;
    }
    int p = 0;
    while (p < top - 1 && st[p] == '0') {
        p++;
    }
    for (int i = p; i < top; i++) {
        cout << st[i];
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
