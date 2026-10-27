#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
char s[N];
int f[N], len, pos;

inline bool mtc(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> (s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(' || s[i] == '[') {
            continue;
        }
        int j = i - f[i - 1] - 1;
        if (j < 1 || !mtc(s[j], s[i])) {
            continue;
        }
        f[i] = f[i - 1] + 2 + f[j - 1];
        if (f[i] > len) {
            len = f[i], pos = i - f[i] + 1;
        }
    }
    for (int i = pos; i < pos + len; i++) {
        cout << s[i];
    }
    cout << "\n";
    return 0;
}
