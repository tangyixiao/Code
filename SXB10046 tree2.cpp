#include <bits/stdc++.h>
using namespace std;

const int N = 3e1 + 5;
string s;
int idx, lc[N], rc[N], tot;
char val[N];

inline int build() {
    char ch = s[idx++];
    if (ch == '.') {
        return 0;
    }
    int rt = ++tot;
    val[rt] = ch;
    lc[rt] = build();
    rc[rt] = build();
    return rt;
}

inline void inorder(int u) {
    if (u == 0) {
        return;
    }
    inorder(lc[u]);
    cout << val[u];
    inorder(rc[u]);
    return;
}

inline void postorder(int u) {
    if (u == 0) {
        return;
    }
    postorder(lc[u]);
    postorder(rc[u]);
    cout << val[u];
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int rt = build();
    inorder(rt);
    cout << "\n";
    postorder(rt);
    cout << "\n";
    return 0;
}
