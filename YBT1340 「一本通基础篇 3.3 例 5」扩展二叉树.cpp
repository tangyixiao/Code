#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
char s[N], a[N], b[N];
int x, y, z;

inline void input() {
    cin >> s;
    return;
}

inline void dfs() {
    char c = s[x++];
    if (c == '.') {
        return;
    }
    dfs();
    a[y++] = c;
    dfs();
    b[z++] = c;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    dfs();
    a[y] = 0, b[z] = 0;
    cout << a << "\n";
    cout << b << "\n";
    return 0;
}