#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char s[N], t[N];
int po[256], L[256], R[256], len[256], m, cur;

int build(int l, int r) {
    if (l > r) {
        return 0;
    }
    int c = s[cur++];
    int k = po[c];
    L[c] = build(l, k - 1);
    R[c] = build(k + 1, r);
    if (L[c] == 0 && R[c] == 0) {
        len[c] = 1;
    } else {
        len[c] = len[L[c]] + len[R[c]];
    }
    return c;
}

void out(int c) {
    if (c == 0) {
        return;
    }
    for (int i = 1; i <= len[c]; i++) {
        cout << (char)c;
    }
    cout << "\n";
    out(L[c]);
    out(R[c]);
}

signed main() {
    cin >> s >> t;
    m = strlen(s);
    for (int i = 0; i < m; i++) {
        po[(int)t[i]] = i;
    }
    out(build(0, m - 1));
    return 0;
}
